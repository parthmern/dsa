// Sort an array of 0s, 1s
// dutch national flag

// Sort an array of 0s and 1s using Dutch National Flag Algorithm

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr{0, 1, 0, 1, 1, 0, 1, 0, 1, 1};  // Input array

    int start = 0;
    int end = arr.size() - 1;
    int point = 0;

    while (point <= end) {
        if (arr[point] == 0) {
            swap(arr[start], arr[point]);
            start++;
            point++;
        } else if (arr[point] == 1) {
            swap(arr[end], arr[point]);
            end--;
        }
    }

    // Output the sorted array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl ;

    //=========================================
    // FOR EACH LOOP
    for (auto val : arr) {
        cout << val << " ";
    }

    return 0;
}
