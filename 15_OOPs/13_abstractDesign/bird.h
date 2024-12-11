#ifndef BIRD_H
#define BIRD_H

#include <iostream>
using namespace std;

class Bird {
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
    // classes that inherits this class
    // has to implement pure virtual fns.
};

class Eagle : public Bird {
public:
    void eat() {
        std::cout << "Eagle is eating\n";
    }
    void fly() {
        std::cout << "Eagle is flying\n";
    }
};

class Sparrow : public Bird {
public:
    void eat() {
        std::cout << "Sparrow is eating\n";
    }
    void fly() {
        std::cout << "Sparrow is flying\n";
    }
};

#endif
