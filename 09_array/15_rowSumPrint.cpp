#include <iostream>
#include <vector>
using namespace std;

int rowWiseSum(int brr[][3], int rows, int cols){

    for(int row=0; row < rows; row++){

        int sum = 0;
        for(int col=0; col < cols; col++){
            cout << brr[row][col] << " " ;
            sum = sum +  brr[row][col] ;
        }

        cout << "=>" << sum << endl;
    }
}

int main(){ 

    int brr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

    cout << "row wise access " << endl;

    rowWiseSum(brr, 3, 3);

    return 0;
}


