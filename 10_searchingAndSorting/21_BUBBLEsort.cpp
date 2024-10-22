#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr, int n){

    

    for(int i=0; i<n; i++){


        bool swapped = false;

        for(int j=0; j<n-i; j++){
            // process ele till n-i element
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1] );
                swapped = true;
            }
        }

        if(swapped==false){
            cout << "here swapped false hitted"<<endl;
            break;
        }

    }

};

int main(){

    vector<int> arr {6, 2, 8, 4, 10};


    bubbleSort(arr, 5);

    for(auto i: arr){
        cout << i << " ";
    }



    return 0;
}