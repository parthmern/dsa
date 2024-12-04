#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool canDistributeHelper(vector<int> &counts, vector<int> &quantity, int ithCustomer) {
    // Base case: all customers are satisfied
    if (ithCustomer == quantity.size()) {
        return true;
    }

    // Try to satisfy the ith customer
    for (int i = 0; i < counts.size(); i++) {
        if (counts[i] >= quantity[ithCustomer]) {
            counts[i] -= quantity[ithCustomer]; // Deduct quantity for the current customer

            if (canDistributeHelper(counts, quantity, ithCustomer + 1)) {
                return true;
            }

            counts[i] += quantity[ithCustomer]; // Backtrack
        }
    }

    return false;
}

bool canDistribute(vector<int> &nums, vector<int> &quantity) {
    unordered_map<int, int> countMap;

    // Count frequency of each number in nums
    for (int num : nums) {
        countMap[num]++;
    }

    // Convert frequency map to a vector
    vector<int> counts;
    for (auto it : countMap) {
        counts.push_back(it.second);
    }

    // Sort quantities in descending order to optimize backtracking
    sort(quantity.rbegin(), quantity.rend());

    return canDistributeHelper(counts, quantity, 0);
}

int main() {
    vector<int> nums = {1, 1, 2, 2};
    vector<int> quantity = {2, 2};

    if (canDistribute(nums, quantity)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
