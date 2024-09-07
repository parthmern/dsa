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

// another version

#include <iostream>

using namespace std;

int main() {
    int n = 5;

    for (int row = 1; row <= n; row++) {
        // Print spaces
        for (int space = 1; space <= n - row; space++) {
            cout << " ";
        }

        // Print increasing numbers
        for (int col = 1; col <= row; col++) {
            cout << col;
        }

        // Print decreasing numbers
        for (int col = row - 1; col >= 1; col--) {
            cout << col;
        }

        cout << endl;
    }

    return 0;
}
