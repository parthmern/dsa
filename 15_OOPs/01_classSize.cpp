#include <iostream>
using namespace std;


class Animal{


};

class Animal2{
    int age;
    int weight;
};

class Animal3{
    int age;
    int weight;
    char ch;
};

int main(){

    cout << "size of animal class (empty class) : " << sizeof(Animal) << endl;    // 1 byte
    cout << "size of animal2 class  : " << sizeof(Animal2) << endl;    // 8 byte
    cout << "size of animal3 class  : " << sizeof(Animal3) << endl;    // 12 byte   (Padding and Greedy alignment)

    return 0;
}