#include <iostream>
#include <vector>

using namespace std;

int partition(int *arr, int s, int e){

    // 1)choose pivot ele
    int pivotIndex = s;
    int pivotEle = arr[s];

    // 2)find right position  for pivot
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivotEle){
            count++;
        }
    }
    // jab loop se bahar aya to pivot ele ka right postion index 
    // read hai 
    int rightIndex = s+count ;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    // 3) small in left | big in right
    int i = s;
    int j = e;

    // while(i<pivotIndex && j>pivotEle){
    //     while(arr[i]<=pivotEle){
    //         i++;
    //     }
    //     while(arr[i]>pivotEle){
    //         j--;
    //     }

    //     // two pointer method and swapping to adjust eles
    //     if(i<pivotIndex && j>pivotEle){
    //         swap(arr[i], arr[j]);
    //     }
    // }


    vector<int> smaller, greater;

    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivotEle) {
            smaller.push_back(arr[i]);
        } else {
            greater.push_back(arr[i]);
        }
    }

    // Rebuild the array with smaller, pivot, and greater elements
    int index = s;
    for (int num : smaller) {
        arr[index++] = num;
    }

    pivotIndex = index; // Correct position of pivot
    arr[index++] = pivotEle;

    for (int num : greater) {
        arr[index++] = num;
    }



    return pivotIndex;
}

void quickSort(int *arr, int n, int s, int e){

    // basecase
    if(s>=e){
        return;
    }

    // partition logic
    int p = partition(arr, s, e);

    // rr
    quickSort(arr,n,s,p-1);   // left
    quickSort(arr,n,p+1,e);  // right

}

int main(){

    int arr[] = {8,1,3,4,20,50,30};
    int n = 7;

    int s = 0;
    int e = n-1;

    quickSort(arr, n ,s,e);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}