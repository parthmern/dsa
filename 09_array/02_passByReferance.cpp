// Arrays are not truly passed by value in C++ ( can do this with int, char)
// array can only pass by REFERANCE

#include <iostream>
using namespace std; 

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}


void modifyArray(int arr[]) {
    arr[0] = 100; // This modifies the original array
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};

    cout << numbers[0] << " | " << numbers[1] << " | " << numbers[2] << endl ;  // 1 | 2 | 3
    modifyArray(numbers);
    cout << numbers[0] << " | " << numbers[1] << " | " << numbers[2] << endl ; // 100 | 2 | 3
    // numbers[0] is now 100
    // so pass by ref

    //==============================
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printArray(numbers, size);
    // we have to pass array with it SIZE



}