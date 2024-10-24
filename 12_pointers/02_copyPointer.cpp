#include <iostream>

using namespace std;

void otherFunc(int arry[]){
    cout << "size under other func where array passed " << sizeof(arry) << endl;
}

int main(){

    int a = 5;
    int*ptr = &a;

    int* dptr = ptr;

    cout << *ptr << endl;   //5
    cout << *dptr << endl;  //5

    int arr[4] = {45,44,43,23};

    cout << arr << &arr << &arr[0] << endl;// same

    cout << *arr+1 << endl;//46

    cout << *(arr+1) << arr[1] << endl; // same 44

    cout << 2[arr] << arr[2] << endl; // same 43

    // =================================


    char ch[10] = "Babbar";

    char *c = ch;

    cout << ch << endl; // Babbar

    cout << *ch << endl;

    int arry[10] = {45,44,43,23};
    cout << "size under main func" << sizeof(arry) << endl;

    otherFunc(arry);

    return 0;
}