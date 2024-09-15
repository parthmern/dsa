#include <iostream>
#include <vector>
using namespace std;

bool findKey(int brr[][3], int rows, int cols, int key){
    bool flag = false ;
    for(int row=0; row < rows; row++){


        for(int col=0; col < cols; col++){
            if(brr[row][col] == key){
                flag = true ;
                break;
            }
        }
    }

    return flag ;
}

int main(){ 

    int brr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };

    cout << "available or not" << findKey(brr, 3, 3, 7) << endl ;

    return 0;
}