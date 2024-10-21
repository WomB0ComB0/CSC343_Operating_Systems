#include <algorithm> // std::min_element
#include <errno.h>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <stdlib.h>    // rand(), srand(), exit()
#include <sys/types.h> // pid_t
#include <sys/wait.h>  // wait()
#include <time.h>      // rand()
#include <unistd.h>    // fork(), getpid()
#include <vector>

using namespace std;

/**
 * @brief Slices a vector from the given start index to the end index.
 *
 * @param arr const reference to the original vector of integers
 * @param start starting index of the slice (inclusive)
 * @param end ending index of the slice (exclusive)
 *
 * @return std::vector<int> A new vector containing the sliced elements.
 *
 * @note If the start index is less than 0, it will be adjusted to 0.
 *       If the end index is greater than the size of the vector, it will be adjusted to the vector size.
 *
 * @example
 * std::vector<int> v = {1, 2, 3, 4, 5};
 * std::vector<int> sliced = slice(v, 1, 4); // sliced will be {2, 3, 4}
 */
std::vector<int> slice(const std::vector<int> &arr, int start, int end) {
    // Ensure the slice indices are valid and adjust them if necessary.
    if (start < 0) start = 0;
    if (end > arr.size()) end = arr.size();

    // Create a vector to store the sliced part and copy the elements from the original vector.
    std::vector<int> result(arr.begin() + start, arr.begin() + end);

    return result;
}

int main() {
    try {
        const int SIZE = 20;
        const int MID = SIZE / 2;

        // Seed random number generator
        srand(time(NULL));

        // Initialize the array with random numbers
        std::vector<int> arr(SIZE);
        for (int i = 0; i < SIZE; ++i) {
            arr[i] = rand() % 100; // Random numbers between 0 and 99
        }

        // Display the array
        std::cout << "Array: ";
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // Fork to create a child process
        pid_t pid = fork();

        if (pid < 0) {
            // Fork failed
            std::cerr << "Fork failed." << std::endl;
            return 1;
        }

        if (pid == 0) {
            // Child process: Find minimum in the second half of the array
            std::vector<int> second_half = slice(arr, MID, SIZE);
            int min_second_half = *std::min_element(second_half.begin(), second_half.end());
            std::cout << "Child process (PID: " << getpid() << ") found minimum in second half: " << min_second_half
                      << std::endl;
            exit(0); // Exit the child process
        } else {
            // Parent process: Find minimum in the first half of the array
            std::vector<int> first_half = slice(arr, 0, MID);
            int min_first_half = *std::min_element(first_half.begin(), first_half.end());
            std::cout << "Parent process (PID: " << getpid() << ") found minimum in first half: " << min_first_half
                      << std::endl;

            // Wait for the child process to finish
            wait(NULL);

            // Find overall minimum
            int overall_min = *std::min_element(arr.begin(), arr.end());
            std::cout << "Overall minimum in the array: " << overall_min << std::endl;
        }

    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}
