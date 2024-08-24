#include <iostream>
using namespace std; 

int main(){

    // implicit 
    char ch = 97 ;           // giving int value but converting and storing into character value
    cout << ch << endl;      // output : a

    int num = 'b';           // giving char value but converting and storing into int value
    cout << num << endl;     // output : 98


    // explicit
    double d = 5.55;
    int ans = (int) d;       // double d is converting into int explicitly and assign to int ans
    cout << ans << endl;     // output : 5
 
    return 0;
}