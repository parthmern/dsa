#include <iostream>
#include <vector>
using namespace std;

int pivotEle(vector<int> arr){

    int s = 0;
    int e = arr.size()-1;   
    int mid = s+(e-s)/2;

    while(s<=e){

        if(s==e){
            // single ele
            return s;
        }

        // boundries are im else leetcode gives error
        if(mid < e && arr[mid] > arr[mid + 1]){
            return mid;
        }
        else if(mid > s && arr[mid] < arr[mid - 1]){
            return (mid-1);
        }

        else if( arr[s] < arr[mid] ){
            // we are in first line
            // move to second line so right side
            s = mid+1;
        }
        else{
            // we are in second line
            // so move to first line so left serach
            e = mid-1;
        }

        mid = s+(e-s)/2;
        cout <<" updated" << s << e << mid << endl;

    }

    cout << s << e <<  mid << endl;
    return -1;
}


int binarySearch(vector<int> arr, int s, int e, int target) {
    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] > target) {
            e = mid - 1; // Move left
        } else {
            s = mid + 1; // Move right
        }
    }

    return -1; 
}

int main(){


    vector<int> v{1,3};

    int pivot = pivotEle(v);

    cout << "pivot" << pivot << endl;

    int target = 0;

    int ans = 0;

    if (pivot == -1) {
        // No pivot means array is not rotated, perform normal binary search
        ans = binarySearch(v, 0, v.size() - 1, target);
    } else if (target >= v[0] && target <= v[pivot]) {
        // Search in the first part
        ans = binarySearch(v, 0, pivot, target);
    } else {
        // Search in the second part
        ans = binarySearch(v, pivot + 1, v.size() - 1, target);
    }

    cout << ans << endl;



    return 0;
}