#include <iostream>
using namespace std;

int main() {
    int a = 5;  // Initial value of a

    // Pre-increment
    a = 5;  // Reset a to its original value
    int preInc = ++a;  
    cout << "Pre-Increment: a = " << a << ", preInc = " << preInc << endl;  // a = 6, preInc = 6

    // Post-increment
    a = 5;  // Reset a to its original value
    int postInc = a++;
    cout << "Post-Increment: a = " << a << ", postInc = " << postInc << endl;  // a = 6, postInc = 5

    // Pre-decrement
    a = 5;  // Reset a to its original value
    int preDec = --a;
    cout << "Pre-Decrement: a = " << a << ", preDec = " << preDec << endl;  // a = 4, preDec = 4

    // Post-decrement
    a = 5;  // Reset a to its original value
    int postDec = a--;
    cout << "Post-Decrement: a = " << a << ", postDec = " << postDec << endl;  // a = 4, postDec = 5

    //=========================================

    // Pre-increment
    a = 5;
    cout << "Before pre-increment: " << a << endl;  // Output: 5
    cout << "Pre-increment: " << ++a << endl;       // Output: 6
    cout << "After pre-increment: " << a << endl;   // Output: 6

    // Post-increment
    a = 5;
    cout << "\nBefore post-increment: " << a << endl;  // Output: 5
    cout << "Post-increment: " << a++ << endl;         // Output: 5
    cout << "After post-increment: " << a << endl;     // Output: 6

    // Pre-decrement
    a = 5;
    cout << "\nBefore pre-decrement: " << a << endl;  // Output: 5
    cout << "Pre-decrement: " << --a << endl;         // Output: 4
    cout << "After pre-decrement: " << a << endl;     // Output: 4

    // Post-decrement
    a = 5;
    cout << "\nBefore post-decrement: " << a << endl;  // Output: 5
    cout << "Post-decrement: " << a-- << endl;         // Output: 5
    cout << "After post-decrement: " << a << endl;     // Output: 4


    // =============================================
    a = 5;
    cout << (++a) * (++a) << endl;   // 49     // ye compiler depenedent bhi hai
    // but how ??

    return 0;
}
