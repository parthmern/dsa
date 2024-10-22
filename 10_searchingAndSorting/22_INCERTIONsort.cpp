#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr, int n){

    for(int i=1; i<n; i++){
        
        int temp = arr[i];

        int j=i-1;
        for(; j>=0; j--){

            if(arr[j]>temp){
                // shift
                arr[j+1] = arr[j];
            }
            else{   // ruk jao
                break;
            }

        }
        arr[j+1] = temp;

    }
};

int main(){

    vector<int> arr {6, 2, 8, 4, 10};


    insertionSort(arr, 5);

    for(auto i: arr){
        cout << i << " ";
    }



    return 0;
}