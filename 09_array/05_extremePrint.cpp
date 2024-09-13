// Given an array int arr[] = {10, 20, 30, 66, 5};
// Output: 10 5 20 66 30

#include <iostream>
using namespace std;



int main(){

    int arr[] = {10, 20, 30, 66, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int start = 0;
    int end = size - 1 ;

    //cout << size << endl ;

    while(arr){

        cout<< arr[start] << " ";
        start ++ ;

        if(start>end){
            break;
        }

        cout << arr[end] << " "  ;
        end -- ;
    }

    return 0;
}