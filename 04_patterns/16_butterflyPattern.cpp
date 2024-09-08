// *       *
// **     **
// ***   ***
// **** ****
// *********
// **** ****
// ***   ***
// **     **
// *       *


#include <iostream>

using namespace std;

int main(){

    int n = 5; 

    // upper part    
    for(int row=0; row< n-1; row++){

        // initial star
        for(int col=0; col<row+1 ; col++){
            cout << "*"; 
        }

        // space
        // 0->7
        // 1->5
        // 2->3
        // 3->1
        // formula = 2*n - 2*N - 1 where N = row+1 if row starts from 0 then
        for(int col=0; col< 2*n - 2*(row+1) - 1 ; col++){
            cout << " ";
        }

        for(int col=0; col<row+1 ; col++){
            cout << "*"; 
        }

        cout << endl;
    }

    // middle line only
    for(int col=0; col< 2*n -1; col++){
        cout << "*";
    }
    cout<< endl;

    // below part
    for(int row=0 ; row<n-1 ; row++){

        for(int col=0; col< n - row - 1; col++){
            cout << "*";
        }

        for(int col=0; col< 2*row+1 ; col++){
            cout << " ";
        }

        for(int col=0; col< n - row - 1; col++){
            cout << "*";
        }

        cout << endl;
    }



    return 0;
}