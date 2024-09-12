#include <iostream>

using namespace std; 

int main(){

    int arr[5]; 

    cout << arr << endl ;    // 0x61fefc
    cout << &arr << endl ;   // 0x61fefc

    int numa[5] = {1, 2, 3, 4, 5};
    int numb[] = {1, 2, 3, 4, 5};

    int numc[10] = {1, 2, 3, 4, 5};
    cout << numc[7] << endl ;   // 0 not GBV
    // int numd[4] = {1, 2, 3, 4, 5};   // error bcz size is smaller

    int n = 0 ;
    // cin >> n ;
    // int nume[n];  // bad practise
    // use dynamic array insted of this

    int numf[5] = {1, 2, 3, 4, 5};
    // numf[0] value at (baseAddress + index*datatype) = (200 + 0*4)
    // numf[1] = (200 + 1*4)

    int numg[2];
    cout << numg[0] << " " << numg[1] << endl ;     // GBV 6422204 1978694717

    // memset in array
    // https://www.geeksforgeeks.org/memset-in-cpp/


    return 0 ;
}