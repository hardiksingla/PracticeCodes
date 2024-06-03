#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;

        // Print array after each iteration
        printf("Iteration %d: ", i);
        printArray(arr, n);
    }
}

int main() {
    int myArray[] = {5, -10, 11, 29, -2, 0, 68, 19, 72, 65, 56, 20, 36, 54, 101, -9, 2, 23};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);

    printf("Original Array: ");
    printArray(myArray, arraySize);

    insertionSort(myArray, arraySize);

    printf("Final Sorted Array: ");
    printArray(myArray, arraySize);

    return 0;
}
