// 2d array
// https://www.geeksforgeeks.org/cpp-multidimensional-array/

// int two_d[noOfROWS][noOfCOLS]
// we are just visulaizing it as
// int arr[3][3] ; 
// Visualization of the 2D array:
//  ------------------------------------
// | arr[0][0] | arr[0][1] | arr[0][2] |
//  ------------------------------------
// | arr[1][0] | arr[1][1] | arr[1][2] |
//  -----------------------
// | arr[2][0] | arr[2][1] | arr[2][2] |
//  ------------------------------------

// Memory layout of arr[3][3] (stored in a contiguous block):
//  ------------------------------------------------------------------------------------------------------
// | arr[0][0] | arr[0][1] | arr[0][2] | arr[1][0] | arr[1][1] | arr[1][2] | arr[2][0] | arr[2][1] | arr[2][2] |
//  ------------------------------------------------------------------------------------------------------
// Memory indexes:
//  ------------------------------------------------------------------------------------------------------
// |     0     |     1     |     2     |     3     |     4     |     5     |     6     |     7     |     8     |
//  ------------------------------------------------------------------------------------------------------
// Memory addresses: (assuming 4 bytes per int)
//  ------------------------------------------------------------------------------------------------------
// | 0x1000    | 0x1004    | 0x1008    | 0x100C    | 0x1010    | 0x1014    | 0x1018    | 0x101C    | 0x1020    |
//  ------------------------------------------------------------------------------------------------------


// how can memory find it using index
// FORMULA of index = C * i + j
// c = total no of cols
// r = total no of rows
// i = i th row
// j = j th col

// ex. to find 4 value th which is stored at arr[1][2]
// = 3 * 1 + 2 == 5 th index

#include <iostream>
#include <vector>
using namespace std;

int main(){ 

    int arr[3][3] ;

    int brr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    //           = { 
    //                {1,2,3},
    //                {4,5,6},
    //                {7,8,9}
    //             }

    cout << brr[2][2] << endl; //9

    cout << "taking input row wise " << endl;
    // taking input row wise

    for(int row=0; row < 3; row++){

        for(int col=0; col < 3; col++){
            cin >> brr[row][col] ;
        }

    }

    // col wise input taking
    // for(int row=0; row < 3; row++){

    //     for(int col=0; col < 3; col++){
    //         cin >> brr[col][row] ;
    //     }

    // }

    cout << "row wise access " << endl;
    // row wise access 
    for(int row=0; row < 3; row++){

        for(int col=0; col < 3; col++){
            cout << brr[row][col] << " " ;
        }

        cout << endl;
    }

    cout << "printing col wise" << endl; 
    // col wise access
    for(int row=0; row < 3; row++){

        for(int col=0; col < 3; col++){
            // just chaning col<->row
            cout << brr[col][row] << " " ;
        }

        cout << endl;
    }

    return 0;
}







