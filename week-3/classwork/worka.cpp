#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    pid_t c_pid;
    c_pid = fork();

    if (c_pid < -1) {
        perror("fork error");
        exit(EXIT_FAILURE);
    } else if (c_pid > 0) {
        //  wait(nullptr);
        cout << "printed from parent process " << getpid() << endl;
        cout << "return code " << c_pid << endl;
    } else { // c_pid=0
        cout << "printed from child process " << getpid() << endl;
    }
    exit(0);
}