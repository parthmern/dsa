#include <iostream>

using namespace std;

void mergeInPlace(int *arr, int s, int e){
    
    int totalLength = (e-s) + 1;
    int gap = (totalLength/2) + (totalLength%2);

    while (gap>0)
    {
        int i = s;
        int j = s+gap;

        while(j<=e){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
            i++;
            j++;

        }
        
        // gap agar 1 hai to usko break karne k liye 0 de diya
        gap = gap<=1 ? 0 : ((gap/2) + (gap%2));

    }

}

void mergeSort(int *arr, int s, int e){

    // base case
    if(s==e){
        // single element
        return;
    }

    // rr
    int mid = (s+e)/2;
    // left part sort 
    mergeSort(arr ,s, mid);

    // right part sort
    mergeSort(arr, mid+1, e);

    // merge two sorted arr
    mergeInPlace(arr,s,e);

}

int main(){

    int arr[] = {4,5,13,2,12};

    int n = 5;
    
    int s = 0;
    int e = n-1;

    mergeSort(arr,s,e);

    for(int i=0; i<n;i++){
        cout << arr[i] << " ";
    }


    return 0;
}