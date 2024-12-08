#include <iostream>
using namespace std;

class Maths{
    public:
        int sum(int a, int b){
            cout << "int a, int b called" << endl;
            return a+b;
        }
        int sum(int a, int b, int c){
            cout << "int a, int b, int c called" << endl;
            return a+b+c;
        }
        float sum(int a, float b){
            cout << "int a, float b called" << endl;
            return a+b;
        }
};

int main(){

    Maths obj;
    cout << obj.sum(2,5) << endl;
    cout << obj.sum(1,2,3) << endl;
    // cout << obj.sum(1, 4.4) << endl; // error bcz 4.4 is bydefault double (not float)
    cout << obj.sum(1, 4.4f) << endl;

    return 0;
}