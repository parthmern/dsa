//     *  
//    * *  
//   * * *  
//  * * * *  
// * * * * *
//* * * * * * 
//* * * * * * 
// * * * * *
//  * * * * 
//   * * * 
//    * * 
//     *  

#include <iostream>
using namespace std;

int main() {
    int rows = 6;  

    // fullPyramid
    for(int i=0; i< rows; i++){
        for(int j=0; j<rows-i-1 ; j++){
            cout << " ";
        }

        for(int z=0; z< i+1; z++){
            cout << "* " ;
        }
        
        cout << endl ;
    }

    // invertedPyramid
     for(int i=0; i< rows; i++){
       
       for(int j=0; j<i; j++){
        cout << " ";
       }

       for(int z=0; z<rows-i ; z++){
        cout << "* ";
       }
        
        cout << endl ;
    }
    

    

    return 0;
}