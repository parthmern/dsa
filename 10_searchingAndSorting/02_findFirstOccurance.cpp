#include <iostream>
using namespace std;

int binarySearchFirstOcc(int arr[], int size, int target){

    int start = 0;
    int end = size -1;
    int mid = start + (start+end) /2;

    int ans;

    // end start se bada nhi hona chiye
    while( start <= end ){

        int element = arr[mid];
        
        if(arr[mid] == target){
            // store ans  
            ans = mid;

            // do left search ---- CHNAGE ONLY
            end = mid - 1;
        }
        else if(element > target){
            // search in left
            end = mid - 1;
        }
        else if(element < target){
            // search in right
            start = mid + 1;
        }

        mid = start + (end-start)/2 ;

    }

    return ans;

}

int main(){

    int arr[] = {1,3,4,4,4,4,4,6,7,9};

    int size = 10;
    int target = 4;

    int ans = binarySearchFirstOcc(arr, size, target);

    if(ans>=0){
        cout << "first occ index is =>" << ans << endl;
    }

    return 0;
}