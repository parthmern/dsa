#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearchLastOcc(int arr[], int size, int target){

    int start = 0;
    int end = size -1;
    int mid = start + (end - start) / 2;

    int ans;

    // end start se bada nhi hona chiye
    while( start <= end ){

        int element = arr[mid];
        
        if(arr[mid] == target){
            // store ans  
            ans = mid;

            // do right search ---- CHNAGE ONLY
            start = mid + 1;
        }
        else if(element > target){
            // search in left
            end = mid - 1;
        }
        else if(element < target){
            // search in right
            start = mid + 1;
        }

        mid = start + (end - start) / 2;

    }

    return ans;

}

int main(){

    int arr[] = {1,3,4,4,4,4,4,6,7,9};

    int size = 10;
    int target = 4;

    int ans = binarySearchLastOcc(arr, size, target);

    if(ans>=0){
        cout << "last occ index is =>" << ans << endl;
    }

    std::vector<int> v{1,3,4,4,4,4,4,6,7,9};
    // Lower bound
    auto lb = lower_bound(v.begin(), v.end(), 4);
    cout << "first occ index ==>" << lb-v.begin() << endl;

    auto ub = upper_bound(v.begin(), v.end(), 4);
    cout << "last occ index ==>" << ub-v.begin()-1 << endl;


    return 0;
}