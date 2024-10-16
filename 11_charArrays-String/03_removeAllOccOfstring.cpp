#include <iostream>
#include <string>

using namespace std;

string removeOccurrences(string s, string part) {
    int pos = s.find(part);

    // npos means no position means wo exist nhi kar rhi
    while (pos != string::npos) {
        s.erase(pos, part.length());
        pos = s.find(part);
    }

    return s;
}

int main() {
    string input= "daabcbaabcbc" , part = "abc";
    // cout << "Enter the main string: ";
    // cin >> input;
    // cout << "Enter the substring to remove: ";
    // cin >> part;

    string result = removeOccurrences(input, part);
    cout << "String after removing occurrences of \"" << part << "\": " << result << endl;

    return 0;
}
