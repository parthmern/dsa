#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int size, int target){

    int start = 0;
    int end = size-1;
    //int mid = (start+end)/2 ;

    int mid = start + (end-start)/2 ;

    while(start <= end){

        int element = arr[mid];

        if(element == target){
            return mid;
        }
        else if(element > target){
            // search in left
            end = mid - 1;
        }
        else if(element < target){
            // search in right
            start = mid + 1;
        }

        mid = start + (end-start)/2 ;

    }

    return (-1); // return invalid index

}

int main(){

    int arr[] = {2,4,6,8,10,12,16};

    int size = 7;
    int target = 2;

    int indexOfTarget = binarySearch(arr, size, target);

    if(indexOfTarget == -1){
        cout << "target not found" << endl;
    }
    else{
        cout << "target's index is => " << indexOfTarget << endl;
    }

    // #include <algorithm>

    // on vector -------------------------
    std::vector<int> v{1,2,3,4,5,6} ;

    if (binary_search(v.begin(), v.end(), 3)) {
        cout << "3 is found in the vector." << endl;
    } else {
        cout << "3 is not found in the vector." << endl;
    }

    // on array --------------------------
    int arry[] = {1,2,3,4,5,6};
    int sizeOfarry = 6;

    // binary_search(intialAddress, lastElementAddress, target)
    if (binary_search(arry, arry+sizeOfarry, 3)) {
        cout << "3 is found in the vector." << endl;
    } else {
        cout << "3 is not found in the vector." << endl;
    }
    



    return 0;
}