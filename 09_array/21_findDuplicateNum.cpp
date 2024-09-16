// https://leetcode.com/problems/find-the-duplicate-number/description/


#include <iostream>
#include <vector>
#include <algorithm> // For sort()

using namespace std;

int duplicateEle(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort the vector

    // Iterate through the sorted vector until second last element to find the duplicate
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] == nums[i + 1]) { // If adjacent elements are equal, we've found the duplicate
            return nums[i];
        }
    }

    return -1; // In case there's no duplicate (though problem guarantees there is one)
}

int main() {
    vector<int> arr{1, 3, 4, 2, 2};

    int duplicate = duplicateEle(arr);
    cout << "Duplicate element is: " << duplicate << endl;

    return 0;
}
