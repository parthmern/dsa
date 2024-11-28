#include <iostream>
#include <vector>
#include <limits>
#include <climits> 
using namespace std;

int maxSubArray(vector<int> &arr, int s, int e) {
    // Base case: single element
    if (s == e) {
        return arr[s];
    }

    int maxOfLeftBorderSum = INT_MIN;
    int maxOfRightBorderSum = INT_MIN;

    int mid = (s + e) / 2;

    // Recursively find the maximum sum in the left and right halves
    int maxLeftSum = maxSubArray(arr, s, mid);
    int maxRightSum = maxSubArray(arr, mid + 1, e);

    // Calculate maximum cross-border sum
    int leftBorderSum = 0;
    for (int i = mid; i >= s; i--) {
        leftBorderSum = leftBorderSum + arr[i];
        maxOfLeftBorderSum = max(maxOfLeftBorderSum, leftBorderSum);
    }

    int rightBorderSum = 0;
    for (int i = mid + 1; i <= e; i++) {
        rightBorderSum += arr[i];
        maxOfRightBorderSum = max(maxOfRightBorderSum, rightBorderSum);
    }

    int crossBorderSum = maxOfLeftBorderSum + maxOfRightBorderSum;

    // Return the maximum of the three cases
    return max(maxLeftSum, max(maxRightSum, crossBorderSum));
}

int main() {


    vector<int> arr {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubArray(arr, 0, arr.size() - 1);
    
    cout << "The maximum subarray sum is: " << result << endl;

    return 0;
}
