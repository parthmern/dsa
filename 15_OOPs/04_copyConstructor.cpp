#include <iostream>
using namespace std;

class Animal {
public:
    int age;
    string name;

    // Constructor
    Animal() {
        cout << "Default constructor called" << endl;
        this->age = 0;
    }

    // Parameterized constructor
    Animal(int age, string name) {
        cout << "Parameterized constructor called" << endl;
        this->age = age;
        this->name = name;
    }

    // Copy constructor
    Animal(Animal & other) {
        cout << "Copy constructor called" << endl;
        this->age = other.age;
        this->name = other.name;
    }
};

int main() {

    Animal a(5, "Buddy"); // Parameterized constructor called

    Animal b = a;         // ONE WAY    // Copy constructor called 
    Animal c(a);          // SECOND WAY  // Copy constructor called

    cout << a.age << endl;
    cout << b.age << endl;
    cout << c.age << endl;

    return 0;
}
