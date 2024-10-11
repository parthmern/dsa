#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int binarySearch(vector<int> arr, int s, int e, int x) {

    int mid = (s+e)/2;  // mid point which indecates elements

    while(s<=e){

        if(arr[mid]==x){
            cout << "Ans" << mid << endl;
            return mid;
        }
        else if( arr[mid] < x ){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }

        cout << mid << endl;
        mid = (s+e)/2;

    }

    // extra return
    return -1;  
}

int exponentialSearch(vector<int> arr, int x) {
    if(arr[0] == x) return 0;

    int i = 1;

    while(i < arr.size() && arr[i] <= x) {
        i = i * 2;
    }

    cout << i/2 << " " << i << endl;

    return binarySearch(arr, i / 2, min(i, (int)arr.size() - 1), x);
}

int main() {
    vector<int> v {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int target = 13;

    exponentialSearch(v, target);



    return 0;
}
