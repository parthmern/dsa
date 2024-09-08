#include <iostream>
using namespace std;

int main(){

    // left shift
    // 5 -> 0000 0101
    // left shifts bits by 1
    //   -> 0000 1010
    // ans 10 

    // 1 bit se left shift karenege to 2*N = answer

    int a = 12;
    int b = a << 1;

    cout << b;   // 24   => 12*2

    int c = a << 2;

    cout << c; // 48    => 12*3

    int d = d << -1 ;

    cout << d ;   // error means gives GarbageValue



    //=======================================
    // right shhift

    // right shift
    // 12 -> 0000 1100
    // right shifts bits by 1
    //   -> 0000 0110
    // ans 6

    // 1 bit se right shift karenge to N/2 = answer
    // ONE CATCH is here find it

    int a = 12;
    int b = a >> 1;

    cout << b << endl;   // 6   => 12/2

    int c = a >> 2;

    cout << c << endl; // 3    => 12/4

    // right shift with negative value will not work correctly
    // as behavior is undefined in C++ with negative shift value

    // int d = a >> -1;
    // cout << d ;   // This would cause an error or garbage value


    // catch is this
    // here if we have negative value and i use right shift then it can gives me high value postitive number
    // here then we cannot apply n/2 everytime


     /*// right shift operator
            int b=25;
            b = b >> 1;
            cout << b << '\n';
            b=25;
            b = b >> 2;
            cout << b << '\n';
            b=25;
            b = b >> 3;
            cout << b << '\n';

            // for negative numbers     compiler is smart so shows divide by 2
            b=-12;
            b = b >> 1;
            cout << b << '\n';
        */

       // https://youtu.be/yjdQHb2elqI?si=Tj3CJHdqJyRViOF0
       // watch here

    return 0;
}