#include <iostream>

using namespace std;

void transpose(int brr[][3], int rows, int cols, int transposeArr[][3]){
    
    for(int row=0; row < rows; row++){


        for(int col=0; col < cols; col++){
            
            // transpose
            // swap(brr[row][col],brr[col][row]);
            // if we do this then again - reagain swapping done so same matrix will be there

            transposeArr[row][col] = brr[col][row] ;

        }
    }

    return ;
}

void print(int brr[][3]){
    for(int row=0; row < 3; row++){

        for(int col=0; col < 3; col++){
            cout << brr[row][col] << " " ;
        }

        cout << endl;
    }
}

int main(){ 

    int brr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

    int transposeArr[3][3];
    print(brr);
    transpose(brr, 3, 3, transposeArr );

    cout << "after transpose" << endl;
    print(transposeArr);

    return 0;
}