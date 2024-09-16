// Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
// Output: -12 -13 -5 -7 -3 -6 11 6 5

// 2 pointer method approach
// dutch national flag

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int size = 9;

    int start=0;
    int end= size-1;
    int point =0;

    while(start<end){
        if(arr[point]>0){
            cout << "swapping" << arr[end] << "and" << arr[point] << endl;
            swap(arr[end], arr[point]);
            end --;
        }
        else if(arr[point]<0){
            swap(arr[start], arr[point]);
            point++;
            start++;
        }else{
            swap(arr[start], arr[end]);
        }
    }

    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}