#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void speak(){
            cout << "speaking" << endl;
        }
};

class Dog : public Animal{
    public:
        // override
        void speak(){
            cout << "Barking" << endl;
        }
};

int main(){

    Animal a;
    a.speak();      // speaking

    Dog obj;
    obj.speak();    // Barking

    Animal* ptr = new Animal();
    ptr->speak();    // speaking

    Dog* doggy = new Dog();
    doggy->speak();  // Barking

    Animal* ani = new Dog();    // parent pointer on child class (upcasting)
    ani->speak();    // speaking            

    // to avoid this we need to use VIRTUAL key word on PARENT function
    ani->speak();   // Barking

    // Dog* pup = new Animal();    // child pointer on parent class (Downcasting)  // giving error
    Dog* pup = (Dog*) new Animal();     // force typecast 

    pup->speak();   // Barking (without virtual)
    pup->speak();   // Speaking (with virtual)

    return 0;
}