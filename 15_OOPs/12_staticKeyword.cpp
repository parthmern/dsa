#include <iostream>
using namespace std;

class Counter {
public:
    static int count;  // Static variable declaration
    int a = 0;         // Instance variable declaration

public:
    void setA(int value) {  // Non-static method to modify `a`
        a = value;
    }

    static void increment() {
        count++;
        cout << "Count: " << count << endl;
        // cout << a << endl;   // error: cannot access instance variable
    }

    static int getCount() {
        return count;
    }

    void showA() const {
        cout << "a: " << a << endl;  // Non-static function accessing `a`
    }
};

// Definition of static variable outside the class
int Counter::count = 0;

int main() {
    Counter::increment();  // Call 1
    Counter::increment();  // Call 2
    Counter::increment();  // Call 3
    cout << "Final Count: " << Counter::getCount() << endl;

    Counter obj1, obj2;
    obj1.setA(5);
    obj1.showA();  // Prints: a: 5

    Counter::count = 10;  // Modifying static variable directly
    cout << "Modified Count: " << Counter::getCount() << endl;  // 10 ans

    return 0;
}
