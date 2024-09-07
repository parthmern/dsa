//1
//2*3
//4*5*6
//7*8*9*10
//7*8*9*10
//4*5*6
//2*3
//1

// lower half complicated 

#include <iostream>

using namespace std; 

int main(){

    int n=4;
    int num = 1;

    // upper part
    for(int row=0; row<n; row++){

        for(int col=0; col<2*row+1; col++){
            
            if(col%2==0){
                cout << num; 
                num++;
            }
            else{
                cout << "*";
            }

        }

        cout << endl;
    }

    ///cout << "-----" << endl;

    int start = num - n ;

    // lower part
    for(int row=0; row<n; row++){

        int k = start ;

        for(int col=0; col<=2*(n-row-1); col++){
            

            if(col%2==0){
                cout << k;
                k++;
            }
            else{
                cout << "*";
            }
        }

        start = start-(n-row-1) ;

        cout << endl;
    }

    return 0;
}