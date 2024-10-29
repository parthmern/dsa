#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& v, int s, int e, int key){

    // base case
    if( s>e ){
        return -1;  // not found
    }
    int mid = (s+e)/2;
    if( v[mid] == key ){ 
        return mid; // got key
    }
    
    
    if( v[mid] < key ){
        binarySearch(v, mid+1, e, key); // right search
    }
    else{
        binarySearch(v, s, mid-1, key);
    }
    
}

int main(){

    vector<int> arr{10,20,40,60,70,90,99};
    int target = 99;

    int s = 0;
    int e = arr.size()-1;

    cout << "at index" << binarySearch(arr,s,e,target);

    return 0;
}