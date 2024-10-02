

#include <iostream>
#include <unordered_map> 
using namespace std;

int main(){ 

    int arr[]= {1, 5, 3, 4, 3, 5, 6};
    int size = sizeof(arr)/sizeof(arr[0]);

    unordered_map<int, int> hash; // [int, int]

    for(int i=0; i<size; i++){

        if(hash[arr[i]] == 1){
            hash[arr[i]]++;
        }else{
            // initalize with 1
            hash[arr[i]] = 1 ;   
        }

    }

    // Print the frequency of each element
    // for(auto& pair : hash){
    //     cout << "Element " << pair.first << " appears " << pair.second << " times." << endl;
        
    // }
    
    // Element 6 appears 1 times.
    // Element 1 appears 1 times.
    // Element 5 appears 2 times.
    // Element 3 appears 2 times.
    // Element 4 appears 1 times.


    // traversing and check
    for(int i=0; i<size; i++){

        if(hash[arr[i]] > 1){
            // means duplicate availabe 2 times appear
            cout << "index+1=>" << i+1 << " and ele is " << arr[i] << endl;
            break;
        }

    }

    


    
}