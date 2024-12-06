#include <iostream>
using namespace std;


class Animal {
    // state
public:
    int age;
    string name;

private:
    int weight;

    // Constructor
public:
    Animal(){
        cout << "Default constructor called" << endl; 
        this->weight = 0;
        this->age = 0;
    }
    Animal(int age, string name, int weight) {
        cout << "parameterized constructor called 3 params" << endl;
        this->age = age;
        this->name = name;
        this->weight = weight;
    }
    Animal(int age){
        cout << "parameterized constructor called 1 age param" << endl;
        this->age = age ;
    }

    // behaviour
    void eat() {
        cout << "eating" << endl;
    }
};


int main(){

    Animal a;   // constructor called
    Animal* ptr = new Animal;   // constructor called 

    Animal b(10,"parth", 15);
    Animal c(10);

    return 0;
}