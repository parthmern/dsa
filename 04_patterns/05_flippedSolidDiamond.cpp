// ****** ******
// *****   *****
// ****     ****
// ***       ***
// **         **
// *           *
// *           *
// **         **
// ***       ***
// ****     ****
// *****   *****
// ****** ******

#include<iostream>
using namespace std;

int main(){

    int totalRows = 6;

    // above half pyramid
    for(int row=0; row<totalRows; row++){
        // half pyramid 
        for(int col=0; col<totalRows-row; col++){
            cout << "*";
        }

        // space wala full pyramid
        for(int col=0; col< 2*row+1 ;col++){
            cout << " ";
        }

        // half pyramid
        for(int col=0; col<totalRows-row; col++){
            cout << "*";
        }
        
        cout << endl;
    }
    
    // ======================
    // below half pyramid
    for(int row=0; row<totalRows; row++){
        // half pyramid 
        for(int col=0; col<row+1; col++){
            cout << "*";
        }

        // space wala full pyramid
        for(int col=0; col< 2*totalRows-2*row-1 ;col++){
            cout << " ";
        }

        // half pyramid
        for(int col=0; col<row+1; col++){
            cout << "*";
        }
        
        cout << endl;
    }

    return 0;
}