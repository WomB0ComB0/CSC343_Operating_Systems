#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class BoundedBuffer {
  public:
    /*
     * The constructor initializes the buffer with the given size.
     * The constructor has the same name as the calss, BoundedBuffer, including it's used
     * to initialize new instances of this class
     * @param size Determine teh capacity of the buffer
     * ':' is used to initialize the member variables of the class (member initializer list),
     * initializes two  member variables, size and buffer
     * size(size) -> initializes the member variable size withh the value of the parameter size
     * buffer(size) -> initializes the member variable, which is presumeably some container
     * (such as std::vector)
     * By calling buffer(size), the buffer is initialized with the given size, meaning it starts
     * with a capacity or initial size of size
     */
    BoundedBuffer(int size) : size(size), buffer(size) {}

    /*
     * The produce method adds an item to the buffer.
     */
    void produce(int item) {
        /*
         * - This creates a unique_lock named lock on a std::mutex named m
         * - immediately locks m when created, the stared resoruce protected by m
         */
        std::unique_lock<std::mutex> lock(m);
        /*
         * - causes the current thread to wait until a specific condition is met. It uses a condition--
         * variable named `not_full`
         * - wait takes wto parameters:
         *   - lock: Thhe unique_lock object, which keeps m locked while waiting
         *   - lambda function [this] { retunr coutn < size; }: This is a predicate---
         *   , a condition that must be true for the waiting to stop
         *   - The lambda function [this] { reutnr count < size; } captures the this pointer---
         *   and checks if count < size
         */
        not_full.wait(lock, [this] { return count < size; });
        /*
         * - If count < size is true, the wait ends immediately.
         * - If count >= size, the thtead is put to sleep  and releases m, allowing other---
         *   threads to modify count.
         * - When not_full.notify_one() or not_full.notify_all() is called by another thread---
         *   , wait will check the ppredicate again. If count < size becomes true, the thread---
         *   will reacquuire lock and resume execution.
         */

        buffer[tail] = item;
        tail = (tail + 1) % size;
        ++count;
        std::cout << "Produce method-add : count  " << count << std::endl;

        not_empty.notify_one();
    }

    int consume() {
        std::unique_lock<std::mutex> lock(m);
        not_empty.wait(lock, [this] { return count > 0; });

        int item = buffer[head];
        head = (head + 1) % size;
        std::cout << "consume method-remove : count  " << count << std::endl;
        std::cout << "consume method-head : head  " << count << std::endl;
        --count;

        not_full.notify_one();
        return item;
    }

  private:
    std::mutex m;
    std::condition_variable not_full, not_empty;
    int size;
    int count = 0;
    int head = 0;
    int tail = 0;
    std::vector<int> buffer;
};

int main() {
    BoundedBuffer buffer(5);

    // This declares a std::thrread object named producer
    /*
     * This is a lambda expresion. A lammbda is an anonymous funciton that can---
     * capture vairables from its surrounding scope.
     *
     * [&]: THis part specifies the capture caluse for the lambda. The & means that the lambda--
     * captures all variables in the surrounding scope by reference. This allows the lambda to--
     * access and modify those variables directly.
     *
     * (){...}: This parentheses indicate that the lambda takes no parameters, and the curly braces--
     * contain the code taht will be executed in the new thread.
     */
    std::thread producer([&]() {
        for (int i = 1; i <= 10; ++i) {
            buffer.produce(i);
            std::cout << "Produced: " << i << std::endl;
        }
    });

    std::thread consumer([&]() {
        for (int i = 1; i <= 10; ++i) {
            int item = buffer.consume();
            std::cout << "Consumed: " << item << std::endl;
        }
    });

    producer.join();
    consumer.join();

    return 0;
}