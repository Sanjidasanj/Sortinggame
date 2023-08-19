#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 5 // Number of elements in the array
#define MAX_ATTEMPTS 3

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));

    int arr[ARRAY_SIZE];
    int choice;

    printf("Welcome to the Sorting Numbers Game!\n");
    printf("You'll be given a shuffled array of numbers. Your task is to sort them.\n");

    // Generate random numbers for the array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }

    printf("Here's your shuffled array:\n");
    printArray(arr, ARRAY_SIZE);

    printf("Choose the order you want to sort:\n");
    printf("1. Ascending Order\n");
    printf("2. Descending Order\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    int sortedArr[ARRAY_SIZE];
    int correct = 1;

    if (choice == 1) {
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                correct = 0;
                break;
            }
        }
    } else if (choice == 2) {
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                correct = 0;
                break;
            }
        }
    } else {
        printf("Invalid choice. Please choose either 1 or 2.\n");
        return 1;
    }

    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        int inputArr[ARRAY_SIZE];
        printf("Attempt %d: Enter the sorted numbers (space-separated): ", attempts + 1);
        for (int i = 0; i < ARRAY_SIZE; i++) {
            scanf("%d", &inputArr[i]);
        }

        int isCorrect = 1;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (inputArr[i] != arr[i]) {
                isCorrect = 0;
                break;
            }
        }

        if (isCorrect && correct) {
            printf("Congratulations! You sorted the array as requested!\n");
            return 0;
        } else {
            printf("Wrong order! Keep trying.\n");
            attempts++;
        }
    }

    printf("Sorry, you've reached the maximum number of attempts.\n");
    printf("You chose to sort in %s order.\n", (choice == 1) ? "ascending" : "descending");
    printf("The correct order was: ");
    printArray(arr, ARRAY_SIZE);

    return 0;
}

