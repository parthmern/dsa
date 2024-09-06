//     *  
//    * *  
//   *   *  
//  *     *  
// *       *
//*         * 
//*         * 
// *       *
//  *     * 
//   *   * 
//    * * 
//     *  

// try to make full diamond first with all fields and then convert it to hollow

// even no = 2n = 2,4,6
// odd no = 2n-1 = 2n+1 = 1,3,5


// #include<iostream>
// using namespace std;
// int main(){
//     int n = 6; // General pattern 
//     // First we have to print the hollow full pyramid
//     for(int i = 0;i<n;i++){ // Number of rows
//         // first print spaces
//         int space = n - i - 1;
//         for(;space>=0;space--){
//             cout<<" ";
//         }
//         // Print stars
//         for(int j = 0;j<2*i+1;j++){
//             // First or last character
//             if(j==0 || j==2*i){
//                 cout<<"*";
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
//     // Print inverted full pyramid pattern
//     for(int i = 0;i<n;i++){
//         // Space print
//         int space = i;
//         for(;space>=0;space--){
//             cout<<" ";
//         }
//         // Print stars
//         for(int j = 0;j<2*n - 2*i - 1;j++){
//             // First or last column
//             if(j==0 || j == 2*n - 2*i - 2){
//                 cout<<"*";
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }


#include<iostream>
using namespace std;

int main(){

    int totalRows ;

    cin >> totalRows;

    for(int row=0; row< totalRows ; row++){

        for(int space=0; space < totalRows-row-1 ; space++){
            cout << " ";
        }

        // half pyramid hollow
        for(int printingStar=0; printingStar < 2*row+1 ; printingStar++){
            // first char
            if(printingStar==0){
                cout << "*";
            }
            // last char
            else if(printingStar ==  2*row){
                cout << "*";
            }
            else{
                cout << " ";
            }
            
        }
        cout << endl ;

        
    }

   // ==========================================
   // inversible half hollow
    for(int row=0; row< totalRows ; row++){
     
        for(int space=0; space < row; space++){
            cout << " ";
        }
        
        for(int printingStar=0; printingStar < 2*totalRows+1 ; printingStar++){
            if(printingStar==0){
                cout << "*";
            }
            // last char
            else if(printingStar == 2*totalRows - 2*row-2){
                cout << "*";
            }
            else{
                cout << " ";
            }
            //cout << "|";
        }

        // cout << "|";
        cout << endl; 

    }

    return 0;
}