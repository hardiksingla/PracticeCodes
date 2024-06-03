#include <iostream>

void generatePascalsTriangle(int n) {
    int* prevRow = nullptr;
    int* currentRow = nullptr;

    for (int i = 0; i < n; ++i) {
        currentRow = new int[i + 1];
        currentRow[0] = 1;

        for (int j = 1; j < i; ++j) {
            currentRow[j] = prevRow[j - 1] + prevRow[j];
        }

        currentRow[i] = 1;

        // Print leading spaces
        for (int k = 0; k < n - i - 1; ++k) {
            std::cout << "  ";
        }

        // Display current row
        for (int j = 0; j <= i; ++j) {
            // Print with proper spacing
            std::cout << currentRow[j] << "   ";
        }
        std::cout << std::endl;

        // Cleanup and update pointers
        delete[] prevRow;
        prevRow = currentRow;
    }

    // Cleanup the last row
    delete[] currentRow;
}

int main() {
    int n;
    std::cout << "Enter the number of rows for Pascal's Triangle: ";
    std::cin >> n;

    generatePascalsTriangle(n);

    return 0;
}
