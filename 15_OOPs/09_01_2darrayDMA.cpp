#include <iostream>
using namespace std;

int main() {
    int rows = 3; // Number of rows
    int cols = 4; // Number of columns

    // Step 1: Allocate an array of pointers for the rows
    int** arr = new int*[rows];

    // Step 2: Allocate an array for each row
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    // Step 3: Initialize the 2D array
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = value++; // Fill array with incremental values
        }
    }

    // Step 4: Print the 2D array
    cout << "2D Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Step 5: Deallocate the 2D array
    for (int i = 0; i < rows; i++) {
        delete[] arr[i]; // Free each row
    }
    delete[] arr; // Free the array of pointers

    return 0;
}
