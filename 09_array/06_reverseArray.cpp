// int arr[] = {10, 20, 30, 40, 50};
// 50 40 30 20 10

#include <iostream>
using namespace std;

int main(){

    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int start = 0;
    int end = size - 1 ;

    while (arr)
    {
        swap(arr[start], arr[end]);

        start++ ;
        end-- ;

        if(start>end){
            break;
        }

    }

    for(int i=0; i<size ;i++){
        cout << arr[i] << " ";
    }
    

    return 0;
}