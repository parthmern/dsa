#include <iostream>
#include <unordered_map>
using namespace std;

// Function to count the frequency and find the first duplicate
void findFirstDuplicate(int arr[], int size) {
    unordered_map<int, int> hash;

    // First loop: Count the frequency of each element
    for (int i = 0; i < size; i++) {
        if (hash[arr[i]] == 1) {
            hash[arr[i]]++;
        } else {
            hash[arr[i]] = 1;
        }
    }

    // Print the frequency of each element
    // for(auto& pair : hash){
    //     cout << "Element " << pair.first << " appears " << pair.second << " times." << endl;
    // }
    
    // Element 6 appears 1 times.
    // Element 1 appears 1 times.
    // Element 5 appears 2 times.
    // Element 3 appears 2 times.
    // Element 4 appears 1 times.

    // Second loop: Find the first element that has appeared more than once
    for (int i = 0; i < size; i++) {
        if (hash[arr[i]] > 1) {
            cout << "index+1 => " << i + 1 << " and element is " << arr[i] << endl;
            break; // Stop after finding the first duplicate
        }
    }
}

void findFirstDuplicatewithOwnhashingWay(int arr[], int size){

    int hash[7] = {0};

    for (int i = 0; i < size; i++) {
        
        for(int j=0; j<size; j++){
            if(i == arr[j]){
                hash[i] = hash[i] + 1;
            }
        }

    }

    for(int i=0; i<size; i++){
        
        if(hash[arr[i]] > 1){
            cout << "index=> " << hash[arr[i]]  << " and element is " << arr[i] << endl;
            break;
        }
    }
}

int main() {
    int arr[] = {1, 5, 3, 4, 3, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    findFirstDuplicate(arr, size);

    findFirstDuplicatewithOwnhashingWay(arr, size);

    return 0;
}
