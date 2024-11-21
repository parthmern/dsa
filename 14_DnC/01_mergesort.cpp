#include <iostream>

using namespace std;

void merge(int *arr, int s, int e){
    int mid = (s+e)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int* leftArr = new int[len1];
    int* rightArr = new int[len2];

    // copy values
    int k = s;
    for(int i=0;i<len1;i++){
        leftArr[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int i=0;i<len2;i++){
        rightArr[i] = arr[k];
        k++;
    }

    // merge two sorted arrays
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrIndex = s;

    while(leftIndex<len1 && rightIndex<len2){
        if(leftArr[leftIndex] < rightArr[rightIndex]){
            arr[mainArrIndex] = leftArr[leftIndex];
            mainArrIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrIndex] = rightArr[rightIndex];
            mainArrIndex++;
            rightIndex++;
        }
    }

    // copy logic for left arr
    while(leftIndex<len1){
        arr[mainArrIndex] = leftArr[leftIndex];
        mainArrIndex++;
        leftIndex++;
    }

    while(rightIndex<len2){
        arr[mainArrIndex] = rightArr[rightIndex];
        mainArrIndex++;
        rightIndex++;
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
    merge(arr,s,e);

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