//1
//2*2
//3*3*3
//4*4*4*4
//4*4*4*4
//3*3*3
//2*2
//1

#include <iostream>
using namespace std ;

int main(){
    int totalRows = 4;

    //above pyramid
    for(int row=0; row< totalRows; row++){

        for(int col=0; col < row+1; col++){
            // cout << row+1 << "*";

            cout << row+1;
            // last char nhi ho to 
            if(col!=row){
                cout << "*";
            }
        }

        cout << endl;
    }

    // below pyramid
   for(int row=0; row< totalRows; row++){

        for(int col=0; col < totalRows-row; col++){

            cout << totalRows-row;
            // last char nhi ho to 
            if(col != totalRows-row-1){
                cout << "*";
            }
        }

        cout << endl;
    }


    return 0;
}

