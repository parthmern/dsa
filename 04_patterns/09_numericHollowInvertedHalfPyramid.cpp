// 123456
// 2   6
// 3  6
// 4 6
// 56
// 6

#include <iostream>

using namespace std;

int main(){

    int totalRows= 6 ; 

    for(int row=0; row<totalRows; row++){

        for(int col=0; col<totalRows-row ; col++){
            if(col==0){
                // first
                cout<<row+1;
            }
            else if(row==0){
                cout<<col+1;
            }
            else if(col== totalRows-row-1){
                // last char
                cout << totalRows; 
            }
            else{
                cout << " ";
            }
        }

        cout << endl;

    }

    return 0;
}
