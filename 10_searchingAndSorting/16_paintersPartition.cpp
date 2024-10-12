#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int countingPainter(vector<int> arr, int mid) {
    int countedPainter = 1;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (currentSum + arr[i] <= mid) {
            currentSum += arr[i];
        } else {
            countedPainter++;
            currentSum = arr[i];

            cout << "countedPainter->" << countedPainter << endl;
        }
    }

    return countedPainter;
}

int binarySearch(vector<int> arr, int sum, int totalPainters) {
    int s = 0; // or can start with MAX ele
    int e = sum;
    int result = e; // Initialize result with the maximum possible value

    while (s <= e) {
        int mid = s + (e - s) / 2;
        int countedPainters = countingPainter(arr, mid);

        if (countedPainters <= totalPainters) {
            // If current mid can be completed by the available painters, try for a better (smaller) answer
            result = mid;
            e = mid - 1;
        } else {
            // If not, increase mid
            s = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> v{10, 20, 30, 40};
    int totalPainters = 2;
    int sum = 10 + 20 + 30 + 40;

    cout << "Minimum time to paint: " << binarySearch(v, sum, totalPainters) << endl;

    return 0;
}
