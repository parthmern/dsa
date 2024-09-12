#include <iostream>
#include <climits>

using namespace std;

int findMax(int arr[], int size) {
    if (size == 0) {
        cerr << "Array is empty" << endl;
        return INT_MIN;  // Return minimum possible integer if array is empty
    }
    
    // int max = arr[0];  // Start with the first element as the maximum
    int max = INT_MIN ;   // good practise if we want to intialize max number then use INT_MIN and if we want to intitalize minimum num then use INT_MAX
    
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];  // Update max if we find a larger element
        }
    }
    
    return max;
}

int main() {
    int numbers[] = {4, 9, 1, 7, 3, 8, 2, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    int maxNumber = findMax(numbers, size);
    
    cout << "The maximum number in the array is: " << maxNumber << endl;
    
    return 0;
}