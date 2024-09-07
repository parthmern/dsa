//********1********
//*******2*2******* 
//******3*3*3****** 
//*****4*4*4*4***** 
//****5*5*5*5*5****


#include <iostream>
using namespace std;

int main(){

    int n=5;

    for(int row=0; row<n; row++){

        // for initial stars
        for(int col=0; col< n+3-row;col++){
            cout << "*";
        }

        for(int col=0; col< 2*row+1;col++){
            if(col%2!=0){
                cout << "*";
            }
            else{
                cout << row+1;
            }
        }

        for(int col=0; col< n+2-row;col++){
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
