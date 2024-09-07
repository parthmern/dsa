//    1
//   121
//  12321
// 1234321
//123454321

// palindrome 
// racecar == ulta karenege each letter = racecar
// left read == right read are same


#include <iostream>

using namespace std;

int main(){

    int n = 5;

    int k = n ;


    for(int row=0; row<n; row++){

        int c=1;

        for(int col=0; col< k; col++){
            
            if(col<n-row-1){
                cout << " ";
            }
            else if(col <=n-1){
                cout << c;
                c++;
            }
            else{
                c--;
                cout << c-1;
            }
            
        }
        k++;

        cout << endl;
    }

    return 0;

}


