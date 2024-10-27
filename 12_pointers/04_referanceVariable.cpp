#include <iostream>
using namespace std;

void increment(int &num) {
    num += 1;
}

int main() {
    int x = 5;
    int &y = x; // y is a reference to x

    cout << "Before increment: " << x << endl; // Outputs 5
    increment(y);
    cout << "After increment: " << x << endl;  // Outputs 6

    return 0;
}
