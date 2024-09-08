

#include <iostream>
using namespace std;

int main(){

    bool a = true ;
    bool b = false ;

    cout << (a & b) ;  // 0 - false

    cout << (a | b) ;  // 1 - true 

    cout << (a ^ b) ;  // XOR (exclusive or ) 1 - true

    // cout << ~a ; 


    cout << (2 & 3 ) << endl;  // 2
    // 2 ->  1 0
    // 3 ->  1 1 (&)
    //       - - 
    //       1 0  so ans is 2

    cout << (5 & 10) << endl ;  // 0
    // 0101
    // 1010  (&)
    // ----
    // 0000


    return 0;
}