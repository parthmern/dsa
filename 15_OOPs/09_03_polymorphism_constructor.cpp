#include <iostream>
using namespace std;

class Animal{

    public:
        Animal(){
            cout << "animal constructor" << endl;
        }

};

class Dog : public Animal {
    public:
        Dog(){
            cout << "Dog constructor" << endl;
        }
};

int main(){

    Animal* a = new Animal();   // animal constructor
    Animal aa;                  // animal constructor
    Dog* b = new Dog();         // animal constructor - Dog constructor
    Dog bb;                     // Dog constructor

    Animal* ani = new Dog();    // animal constructor - Dog constructor
    Dog* pup = (Dog*) new Animal();     // animal constructor

    return 0;
}