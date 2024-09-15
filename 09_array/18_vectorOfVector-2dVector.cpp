#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector< vector<int> > arr ;
    // here vector outer wala hai
    // wo outer vector ki datatype "vector<int>" hai

    // jab hum arr access karte hai tab hum outer vector ko access kar sakte hai
    // jis me push kar ne k liye hame data chiye uski datatype "vector<int>" hona chiye

    vector<int> a{1, 2, 3};
    vector<int> b{2, 4, 6};
    vector<int> c{1, 3, 7};

    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c); 

    for(int row=0; row< arr.size() ; row++){

        for(int col=0; col< arr[row].size() ; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }


    // declare with size
    // muze vector of vector banaana hai means 2d arrray of int
    // vector< vector<int> > brr( rows, vector<int>(cols, initialize value ) );
    // where rows == size of outer vector == no of rows
    // cols == size of inner vector == no of cols
    // vector<int>(cols, initialize value )   == intialize value of outer vector
    // where under "initialize value" == jo inner vector ki intialize value

    vector< vector<int> > brr(3, vector<int>(5, 0));

     for(int row=0; row< brr.size() ; row++){

        for(int col=0; col< brr[row].size() ; col++){
            cout << brr[row][col] << " ";
        }
        cout << endl;
    }
    // 0 0 0 0 0
    // 0 0 0 0 0
    // 0 0 0 0 0


    return 0;
}