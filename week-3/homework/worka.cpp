#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
// #include <stdexcept>
// #include <errno.h>

using namespace std;

int main() {
    try {
        const int MEMORY_SIZE = 16;
        const int PAGE_COUNT = 100;
        const int PAGE_SIZE = 160;  // 160 MB per page
        const int MEMORY_PER_NUMBER = 80;  // 80 MB per unit number

        int memory[PAGE_COUNT] = {0};
        int processCounter = 1;
        int startingAddress = 2000;

        // User memory allocation function
        auto userMemoryAllocation = [&]() {
            srand(time(0)); // Seed random number generator
            /*
            * Loop through memory pages and allocate memory to processes
            * Randomly generate number of pages required for each process
            */
            for (int i = 0; i < PAGE_COUNT; i++) {
                if (memory[i] == 0) { // Check if page is free
                    int pagesRequired = rand() % 30 + 1; // Randomly generate number of pages required
                    int processSize = pagesRequired * MEMORY_PER_NUMBER;
                    int allocatedMemory = pagesRequired * PAGE_SIZE;
                    int unusedSpace = allocatedMemory - processSize;

                    // Allocate pages to process
                    for (int j = 0; j < pagesRequired && i + j < PAGE_COUNT; ++j) {
                        memory[i + j] = processCounter;
                    }

                    // Output process allocation details
                    cout << "| " << processCounter << string(11 - to_string(processCounter).length(), ' ');
                    cout << "| " << startingAddress << string(24 - to_string(startingAddress).length(), ' ');
                    cout << "| " << processSize << string(24 - to_string(processSize).length(), ' ');
                    cout << "| " << unusedSpace << string(17 - to_string(unusedSpace).length(), ' ') << "|\n";

                    // Update starting address and process counter
                    startingAddress += allocatedMemory;
                    processCounter++;

                    // Skip allocated pages in the loop
                    i += pagesRequired - 1;
                }
            }
        };

        // Output report header
        cout << "\nMemory Management Simulation Report:\n";
        cout << "| Process Id | Starting Memory Address | Size of the Process (MB) | Unused Space (MB) |\n";
        cout << "|------------|--------------------------|--------------------------|-------------------|\n";

        // Run memory allocation    
        userMemoryAllocation();

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "An unknown error occurred." << std::endl;
        return 1;
    }

    return 0;
}
