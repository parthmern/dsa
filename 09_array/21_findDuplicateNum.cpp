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


// NEGATIVE MARKING METHOD
int negMarkingMethodDuplicateEle(vector<int>& nums){

    int ans = -1 ;

    for(int i=0; i<nums.size(); i++){

        int index = abs(nums[i]);

        if(nums[index] < 0){
            // already visited ?
            ans = index;
        } else{
            // mark as visited
            nums[index] = nums[index] * (-1) ;
        }

    }

    return ans ;

}


// POSITIONING METHOD
// POSITIONING METHOD (Cyclic Sort approach)
int positionMethodDuplicate(vector<int>& nums) {
    while (nums[0] != nums[nums[0]]) {
        // Swap nums[0] with the element at its correct position nums[nums[0]]
        swap(nums[0], nums[nums[0]]);
    }

    return nums[0]; // The duplicate number
}

int main() {
    vector<int> arr{1, 3, 4, 2, 2};

    // raw array performs shallow copy (error not allowed)
    // int arr1[] = {1, 2, 3};
    // int arr2[] = {4, 5, 6};
    // arr2 = arr1; // This is not allowed in C++

    //performs a deep copy by vector
    vector<int> arr1 = arr;  //  Deep copy for Sorting Method
    vector<int> arr2 = arr;  // Deep copy for Negative Marking Method
    vector<int> arr3 = arr;  // Deep copy for Positioning Method

    int duplicate = duplicateEle(arr1);
    int dup = negMarkingMethodDuplicateEle(arr2);
    int dupp = positionMethodDuplicate(arr3);
    cout << "Duplicate element is: " << duplicate << "---" << dup << "---" << dupp << endl;

    
    return 0;
}
