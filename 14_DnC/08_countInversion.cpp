#include <iostream>
#include <vector>
using namespace std;

long merge(vector<int> &arr, vector<int> &temp, int s, int mid, int e){
    int i = s, j = mid + 1, k = s;

    long count = 0;

    while( i <= mid && j <= e ){
        if( arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{   // arr[j] > arr[j]  // INVERSION COUNT CASE
            temp[k++] = arr[j++];
            count = count + (mid - i + 1);
        }
    }

    while (i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= e){
        temp[k++] = arr[j++];
    }

    // copy temp array to original array
    while(s <= e){
        arr[s] = temp[s];
        s++;
    }

    return count;
}

long mergeSort(vector <int> &arr, vector <int> &temp, int s, int e){
    long count = 0;
    if(s == e){
        return 0;
    }

    int mid = s + (e - s) / 2;

    count += mergeSort(arr, temp, s, mid);
    count += mergeSort(arr, temp, mid + 1, e);

    count += merge(arr, temp, s, mid, e);

    return count;
}

long countInversion(vector <int> arr){
    long count = 0;

    vector<int> temp(arr.size(), 0);

    count = mergeSort(arr, temp, 0, arr.size() - 1);

    return count;
}

int main(){
    // Test case
    vector<int> arr = {2, 4, 1, 3, 5}; // Example input
    long inversions = countInversion(arr);

    cout << "Number of inversions: " << inversions << endl; // Expected output: 3

    return 0;
}
