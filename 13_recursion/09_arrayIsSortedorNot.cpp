#include <iostream>

using namespace std;

bool sortedOrNot(int arr[], int& n, int i, int tempEle){

    // base case
    if( i == n ){
        return true; 
    }

    cout << "for" << tempEle << " " << arr[i] << endl;
    if( tempEle > arr[i] ){
        return false;
    }
    tempEle = arr[i];

    sortedOrNot(arr, n, i+1, tempEle);

}


int main(){

    int arr[] = { 4, 7, 12, 14, 90};
    int n = 5;
    int i = 1;

    cout << sortedOrNot(arr, n, i, arr[0]);

    return 0;

}