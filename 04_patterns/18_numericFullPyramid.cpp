//         1
//       2 3 2
//     3 4 5 4 3
//   4 5 6 7 6 5 4
// 5 6 7 8 9 8 7 6 5

#include <iostream>
using namespace std;

int main(){

    int n = 5 ;

    for(int row=0; row<n; row++){

        int start = row+1;
        bool flag = false; 

        for(int col=0; col< n-(row+1) ; col++){
            cout << " ";
        }

        for(int col=0; col< 2*row+1; col++){
            
            if( start == 2*row+1){
                cout << start ;
                start -- ;
                flag = true ;
            }
            else{
                cout << start;
                if(!flag){
                    start ++ ;
                }else{
                    start -- ;
                }
            }
        }

        cout << endl ;
    }

    return 0;
}