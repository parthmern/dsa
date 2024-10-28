#include <iostream>
#include <climits>   

using namespace std;

int findMaximumEle(int arr[], int n, int i, int& maxi){

    // base case
    if(i>=n){
        return maxi;
    }

    // progress
    if(maxi<arr[i]){
        maxi = arr[i];
    }

    // recursion
    findMaximumEle(arr,n,i+1, maxi);

}


int main(){

    int arr[] = {1,2,3,4,5};
    int n =5;
    int i=0;

    int maxi = INT_MIN;

    cout << findMaximumEle(arr,n,i,maxi)<<endl;

    cout << maxi ;

    return 0;
}