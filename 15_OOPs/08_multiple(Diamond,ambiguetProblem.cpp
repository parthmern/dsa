#include <iostream>
using namespace std;

class A{
    public:
        int chymistry;

    A(){
        chymistry = 101;
    }
};
class B{
    public:
        int chymistry;

    B(){
        chymistry = 420;
    }
};

class C : public A, public B{
    public:
        int maths = 1;
};  

int main(){

    C obj; 
    cout << "chem of A" << obj.A::chymistry << endl; // 101 using scope resolution
    cout << "chem of B" << obj.B::chymistry << endl; // 420

    return 0;
}