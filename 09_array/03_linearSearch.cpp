// linear seach
// go by each - each element to find target

// https://www.geeksforgeeks.org/cpp-program-for-linear-search/


#include <iostream>
using namespace std; 

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index if the target is found
        }
    }
    return -1;  // Return -1 if the target is not found


    // or we can return true/false
}

int main() {
    int numbers[] = {4, 2, 7, 1, 9, 5, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 7;
    
    int result = linearSearch(numbers, size, target);
    
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }
    
    return 0;
}