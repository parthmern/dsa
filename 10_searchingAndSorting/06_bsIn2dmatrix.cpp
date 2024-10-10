#include <iostream>
#include <vector>
using namespace std;

int bsIn2d(vector< vector<int> > v, int target) {
    int start = 0;
    int end = v.size() * v[0].size() - 1;
    int totalCols = v[0].size();
    
    while (start <= end) {
        int mid = (start + end) / 2;
        int rowIndex = mid / totalCols; 
        int colIndex = mid % totalCols;
        int element = v[rowIndex][colIndex];

        if (element == target) {
            cout << "Matched element: " << element << endl;
            cout << "rowIndex: " << rowIndex << ", colIndex: " << colIndex << endl;
            return mid;  // Return the position of the element or some signal
        }
        else if (element > target) {
            // Search in left half
            end = mid - 1;
        }
        else {
            // Search in right half
            start = mid + 1;
        }
    }
    
    return -1;  // Return -1 if the target is not found
}

int main() {
    vector< vector<int> > v {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    int target = 13;

    int result = bsIn2d(v, target);

    if (result == -1) {
        cout << "Element not found!" << endl;
    }

    return 0;
}
