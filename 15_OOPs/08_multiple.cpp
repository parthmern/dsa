#include <iostream>
using namespace std;

class A{
    public:
        int physics;
};
class B{
    public:
        int chymistry;
};

class C : public A, public B{
    public:
        int maths;
};  

int main(){

    C obj;
    cout << obj.physics << obj.chymistry << obj.maths ; // all accessible

    return 0;
}