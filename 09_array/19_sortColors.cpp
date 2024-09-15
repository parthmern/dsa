#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int zero=0, one=0, two=0 ;

        for(int i=0; i< nums.size(); i++){
            if(nums[i] == 0){
                zero++;
            }else if(nums[i] == 1){
                one++;
            }else{
                two++;
            }
        }
        
        for(int i=0; i< nums.size(); i++){

            if(zero!=0){
                nums[i] = 0;
                zero--;
            }else if(one!=0){
                nums[i] = 1;
                one--;
            }else if(two !=0){
                nums[i] = 2;
                two--;
            }
        }

        return ;
    }


    void inplaceSortColor(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, point = 0;

        while (point <= end) {
            if (nums[point] == 0) {
                swap(nums[start], nums[point]);
                start++;
                point++;
            } else if (nums[point] == 1) {
                point++;
            } else if (nums[point] == 2) {
                swap(nums[point], nums[end]);
                end--;
            }
        }
    }


};

int main() {
    Solution sol;
    vector<int> nums;
    int n, value;

    // Input size of the vector
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input elements of the vector
    cout << "Enter the elements (0, 1, 2): ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        nums.push_back(value);
    }

    // Call sortColors function
    //sol.sortColors(nums);

    // Call inplaceSortColor function
    sol.inplaceSortColor(nums);

    // Output the sorted vector
    cout << "Sorted elements: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
