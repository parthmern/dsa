// Sort an array of 0s, 1s
// dutch national flag


#include <iostream>
#include <vector>
using namespace std; 

int main(){

    vector<int> arr{0,1,0,1,1,0,1,0,1,1} ;

    int start = 0;
    int end = arr.size() - 1;

    int point = 0 ;

    while(point!=end){

        if(arr[point] == 0){
            swap(arr[start], arr[point]);
            start++;
            point++;
        }

        if(arr[point] == 1){
            swap(arr[end], arr[point]);
            end--;
        }

    }

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;

}