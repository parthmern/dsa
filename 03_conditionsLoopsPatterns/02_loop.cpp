#include <iostream>
using namespace std;

int main() {
    cout << "1. For Loop:\n";
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << "\n\n";

    cout << "2. While Loop:\n";
    int j = 0;
    while (j < 5) {
        cout << j << " ";
        j++;
    }
    cout << "\n\n";

    cout << "3. Do-While Loop:\n";
    int k = 0;
    do {
        cout << k << " ";
        k++;
    } while (k < 5);
    cout << "\n\n";

    cout << "5. Infinite Loop with break:\n";
    int count = 0;
    while (true) {
        cout << count << " ";
        count++;
        if (count >= 5) break;
    }
    cout << "\n\n";

    cout << "6. Nested Loops:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << i << j << " ";
        }
        cout << endl;
    }
    cout << "\n";

    cout << "7. Loop with continue:\n";
    for (int i = 0; i < 5; i++) {
        if (i == 2) continue;
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
