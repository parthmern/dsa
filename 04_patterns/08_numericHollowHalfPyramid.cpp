//1
//12
//1 3
//1  4
//12345

#include <iostream>
using namespace std; 

int main(){

    int totalRows = 5;

    for(int row=0; row<totalRows; row++){
        
        for(int col=0; col< row+1; col++){
            // cout << "*";
            if(col==0){
                cout << col+1;
            }
            else if(row==totalRows-1){
                cout << col+1;
            }
            else if(col==row){
                cout << row+1;
            }
            else{
                cout << " ";
            }
        }

        cout << endl ;
    }

    return 0;
}