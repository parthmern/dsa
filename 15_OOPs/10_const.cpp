#include <iostream>
using namespace std;

int main(){ 

    const int var = 10;
    // var = 20 ; // error

    // 2) const with pointers
    const int* a = new int(2); // CONST data, nonConst pointer
    // int const *a = new int(2);  //same

    cout << *a << endl;

    // *a = 2;  // error

    int val = 5;
    a = &val;
    cout << *a << endl;


    // -------------------------------------
    int* const b = new int(2);  // CONST pointer, but data not const
    *b = 3;

    int value = 4;
    // b = &value;  // error

    // ----------------------------------------
    const int* const both = new int(2);
    // *both = 5;   // error
    // both = &val; // error
    




    return 0;

}