#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the element at index i
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        // Print array after each iteration
        printf("Iteration %d: ", i + 1);
        printArray(arr, n);
    }
}

int main() {
    int myArray[] = {5, -10, 11, 29, -2, 0, 68, 19, 72, 65, 56, 20, 36, 54, 101, -9, 2, 23};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    printf("Original Array: ");
    printArray(myArray, arraySize);

    selectionSort(myArray, arraySize);

    printf("Final Sorted Array: ");
    printArray(myArray, arraySize);

    return 0;
}
