#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // Merge two sorted subarrays arr[s..m] and arr[m+1..e] in place
    void mergeInPlace(vector<int>& arr, int s, int m, int e) {
        // TODO: implement in-place merging logic
        // Example approach: shifting elements or using the "gap method"

        int len1 = m-s+1;
        int len2 = e-m;
        int gap = ( (len1+len2) / 2) + ( (len1+len2) % 2) ;

        while(gap>0){

            int i = s;
            int j = s+gap;
            
            while(i<=e  && j<=e ){
                //swap
                if( arr[i] > arr[j] ){
                    swap(arr[i], arr[j]);
                }
                i++;
                j++;
            }

            if (gap == 1) break;
            gap = ( (gap) / 2) + ( (gap) % 2);
            
        }

    }

    // Recursive merge sort
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;

        int m = l + (r - l) / 2;

        // Sort left half
        mergeSort(arr, l, m);

        // Sort right half
        mergeSort(arr, m + 1, r);

        // Merge both halves
        mergeInPlace(arr, l, m, r);
    }
};

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    Solution s;
    s.mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
