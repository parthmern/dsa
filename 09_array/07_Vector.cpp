// vector
// dynmaic array which doesnot have size 

// VECTOR apne size ko at that time size se double kar deta hai jab fillout ho jata hai total size se extra


#include <iostream>
#include<vector>  
using namespace std;

int main(){

    // int n ; 
    // cin >> n ;
    // vector<int> arr[n];  
    // dynamic so not bad practise

    vector<int> arr;
    cout << arr.size() << endl ;    // 0 default  // size means kitne eleemts stored hai
    cout << arr.capacity() << endl ;   // 0 default     // capacity means total length 
    cout << (sizeof(arr) / sizeof(int)) << endl ;   // 3  -- compiler dependent stuff

    // insert
    arr.push_back(1);
    arr.push_back(2);
    
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";  
    } // 1 2

    arr.pop_back();

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";  
    } // 1

    // ======================================   
    vector<int> brr(10) ;   // initalize total length 10 with all elem as 0

    // vector<int> brr(10, -1) ;  //  // initalize total length 10 with all elem as -1

    cout << brr.size() << endl ;        //10
    cout << brr.capacity() << endl ;    //10

    for(int i=0; i<brr.size(); i++){
        cout << brr[i] << " ";  
    } // 0 0 0 0 0 0 0 0 0 0

    brr.push_back(1);

    cout << brr.size() << endl ;        //11
    cout << brr.capacity() << endl ;    //20    -- 10 capacity thi mene 1 extra (11 eleement) dal diya to capacity double kar deta hai

    brr.pop_back();

    cout << brr.size() << endl ;        //10
    cout << brr.capacity() << endl ;    //20    -- kam nhi hoga ab

    // =================================================

    vector<int> crr{10, 20, 30, 40, 50} ;

    for(int i=0; i<crr.size(); i++){
        cout << crr[i] << " ";  
    } // 10 20 30 40 50

    cout << "vector crr is empty or not" << crr.empty() << endl ;   // 0 -- false(not empty)


    return 0;
}