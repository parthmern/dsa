//*
//**
//*** 
//****
//*****
//****
//*** 
//**
//*

#include <iostream>
using namespace std ;

// int main(){

//     int n=5;

//     for(int row=0; row<n; row++){

//         for(int col=0; col<row+1; col++){
//             cout << "*";
//         }

//         cout << endl;
//     }


//     for (int row = 0; row < n - 1; row++) {

//         for (int col = 0; col < n - row - 1; col++) {
//             cout << "*";
//         }
//         cout << endl;
//     }

//     return 0;

// }


// short code

int main(){
    int n=5;
    
    for(int i=0; i<2*n-1; i++){
        int cond = i<n ? i : n-(i%n)-2;

        for(int j=0; j<=cond; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}