#include <iostream>

using namespace std;

int main(){

    int a = 5;
    int*ptr = &a;

    int* dptr = ptr;

    cout << *ptr << endl;   //5
    cout << *dptr << endl;  //5

    return 0;
}