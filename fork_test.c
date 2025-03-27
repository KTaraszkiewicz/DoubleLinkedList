#include "doubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void writeToFile(const char* filename, int data) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fprintf(file, "%d\n", data); // Write value to file
    fclose(file);
}

void readFromFileAndDisplay(const char* filename, List* list) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    int value;
    if (fscanf(file, "%d", &value)) {
        // Add value to the list
        insertTail(list, value);
    } else {
        perror("Error reading value from file");
        exit(1);
    }
    fclose(file);
    // Display the contents of the list
    printf("List contents after addition by child process:\n");
    printList(list);
}

void initialize(List* list) {
    insertHead(list, 1);
    insertHead(list, 2);
    insertHead(list, 3);
    insertHead(list, 4);
    printf("List contents after initialization:\n");
    printList(list);
    printf("Parent process PID: %d\n", getpid());
}

void childProcess(const char* filename, int data) {
    writeToFile(filename, data);
    printf("Child process PID: %d, parent PPID: %d, added value: %d\n", getpid(), getppid(), data);
}

int main() {
    const char* filename = "temp.txt";
    List* list = createList();
    initialize(list);

    int numChildren = 5;
    int pid;

    for (int i = 0; i < numChildren; i++) {
        sleep(1);
        pid = fork();
        if (pid == 0) {
            // Child process code
            srand(time(NULL)); // Initialize random number generator with a unique seed
            int randomValue = rand() % 100; // Random value in the range 0-99
            childProcess(filename, randomValue);
            exit(0); // Child process terminates
        } else if (pid < 0) {
            perror("Error creating child process");
            exit(1);
        } else {
            waitpid(pid, NULL, 0); // Wait for the child process to finish
            printf("Parent process PID: %d finished waiting for child process PID: %d\n", getpid(), pid);
            readFromFileAndDisplay(filename, list);
        }
    }

    // Display the final contents of the list
    printf("Final list contents:\n");
    printList(list);

    remove(filename);
    deleteList(list);
    return 0;
}