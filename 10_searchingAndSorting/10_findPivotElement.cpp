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

        if(arr[mid]>arr[mid+1]){
            return mid;
        }
        else if(arr[mid]<arr[mid-1]){
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

int main(){


    vector<int> v{2,4,6,8,9,10};

    cout << pivotEle(v);


    return 0;
}