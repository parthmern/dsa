#include <iostream>
using namespace std;

int main() {
    int rows = 6;  // Number of rows in the pyramid

    for (int i = 0; i < rows; i++) {
        // Print leading spaces
        for (int j = 0; j < (rows - i - 1) * 2; j++) {
            cout << " ";
        }

        // Print stars
        for (int k = 0; k <= i; k++) {
            cout << "*";
            if (k < i) {
                cout << "   ";  // 3 spaces between stars
            }
        }
        cout << endl;
    }

    return 0;
}