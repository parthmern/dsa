//*
//*1*
//*121*
//*12321*
//*121*
//*1*
//*

#include <iostream>
using namespace std;

int main(){

    int n = 4;

    for(int row=0; row<n ; row++){

        bool flag = false ;
        int start = 1;

        for(int col=0; col< 2*row+1; col++){
            
            
            if(row == col){
                flag = true ; 
            }

            if(col == 0 || col == 2*row){
                // first and last char
                cout << "*";
            }
            else{
                cout << start ;
                
                if(flag){
                    start-- ;
                }
                else{
                    start++ ;
                }
            }
        }

        cout << endl;
    }

    // lower part
    for (int row = n - 2; row >= 0; row--) {
        cout << "*";
        for (int col = 1; col <= row; col++) {
            cout << col;
        }
        for (int col = row - 1; col >= 1; col--) {
            cout << col;
        }
        if (row > 0) cout << "*";
        cout << endl;
    }

    return 0;
}