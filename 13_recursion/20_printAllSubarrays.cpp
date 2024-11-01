#include <iostream>
#include <vector>
using namespace std;

void printAllSubarrays(vector<int>& arr, int start, int end) {
    // Base case 
    if (end == arr.size()) {
        return;
    }

    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    printAllSubarrays(arr, start, end + 1);
}

void forLoopFunc(vector<int>& arr) {
    // Loop over all possible starting points
    for (int start = 0; start < arr.size(); start++) {
        int end = start;
        printAllSubarrays(arr, start, end );
    }
}

int main() {
    vector<int> arr {1, 2, 3, 4, 5};

    forLoopFunc(arr);

    return 0;
}
