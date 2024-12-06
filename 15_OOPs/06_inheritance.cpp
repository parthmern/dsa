#include <iostream>
using namespace std;

class Animal {
    private:
        int age;
    public:
        double weight;

    public:
        void eat() {
            cout << "eating animal" << endl;
        }
};

class Dog: public Animal{

    public:
        void print(){
            // cout << this-> age;  // cannot access (private + public=notAvailable)
            cout << this-> weight;
        }

};

int main() {
    
    Dog puppy;
    puppy.eat();    // eating animal

    return 0;
}
