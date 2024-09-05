
//           *
//         *   *
//       *   *   *
//     *   *   *   *
//   *   *   *   *   *
// *   *   *   *   *   *

// #include <iostream>
// using namespace std;

// int main() {
//     int rows = 6;  // Number of rows in the pyramid

//     for (int i = 0; i < rows; i++) {
//         // Print leading spaces
//         for (int j = 0; j < (rows - i - 1) * 2; j++) {
//             cout << " ";
//         }

//         // Print stars
//         for (int k = 0; k <= i; k++) {
//             cout << "*";
//             if (k < i) {
//                 cout << "   ";  // 3 spaces between stars
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }


// ========================================================

//      *     
//     ***
//    *****
//   *******
//  *********
// ***********

#include <iostream>
using namespace std; 

int main(){

    int N = 6;

    for(int i=0; i<N; i++){

        for(int j=0; j < ((2*N)-1) ; j++){
            
            // for space
            if(j< N-i-1){
                cout << " ";
            }
            // for num of stars
            else if(j < i+N){
                cout << "*";
            }
            // for last spaces
            else{
                cout << " ";
            }
        }

        cout << endl ;
    }

    return 0;
}