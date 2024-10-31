#include <iostream>
#include <vector>
#include <limits.h> 
using namespace std;

void maxSumOfNonAdjacentEle(vector<int>& arr, int sum, int& maxi, int i){
    
    //base
    if(i>=arr.size()){
        maxi = max(sum, maxi);
        return;
    }

    //include
    maxSumOfNonAdjacentEle(arr, sum+arr[i], maxi, i+2);

    //exclude
    maxSumOfNonAdjacentEle(arr, sum, maxi, i+1); 

}

int main(){

    vector<int> arr {2,1,4,9};

    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;
    maxSumOfNonAdjacentEle(arr, sum, maxi, i);
    cout << maxi ;
}