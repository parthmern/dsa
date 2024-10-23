#include <iostream>

using namespace std;


int main(){

    int a = 5;
    
    cout << a << endl;  //5  

    cout << &a << endl; //0x61ff08

    int* ptr = &a;

    cout << ptr << endl; // 0x61ff08

    cout << &ptr << endl;   // 0x61ff08

    cout << *ptr << endl;   // 5

    cout << sizeof(ptr) << endl;    // 4

    // BAD practise
    int* pptr;
    cout << *pptr << endl;

    // how to solve
    int* pptrr = nullptr;
    int* pptrrr = 0;
    if(pptrrr != 0){
        cout << *pptrrr << endl;
    }

    

}