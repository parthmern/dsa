#include <iostream>

using namespace std;

void printArr(int arr[], int n, int i){

    // base case
    if(i>=n){
        return;
    }

    cout << arr[i] << " " ;

    printArr(arr,n,i+1);

}

// void usingPointer(int arr[], int n)
void usingPointer(int* ptr, int n){

    // base case
    if(n==0){
        return;
    }

    cout << ptr[0] << *ptr << " " ; // both same

    usingPointer(ptr+1,n-1);

}

int main(){

    int arr[] = {1,2,3,4,5};
    int n =5;
    int i=0;

    printArr(arr,n,i);

    cout << endl;

    usingPointer(arr,n);



    return 0;
}