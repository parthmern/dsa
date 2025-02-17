#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    vector<string> zigzag(numRows);
    int i = 0, row = 0;
    bool direction = 1;

    while (true) {
        if (direction == 1) {
            while (row < numRows && i < s.size()) {
                zigzag[row].push_back(s[i]);
                row++;
                i++;
            }
            row -= 2;
        } else {
            while (row >= 0 && i < s.size()) {
                zigzag[row].push_back(s[i]);
                row--;
                i++;
            }
            row = 1;
        }
        direction = !direction;
        if (i >= s.size()) {
            break;
        }
    }

    string ans = "";
    for (int i = 0; i < zigzag.size(); i++) {
        ans += zigzag[i];
    }

    return ans;
}

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string output = convert(s, numRows);
    cout << "Output: " << output << endl;
    return 0;
}
