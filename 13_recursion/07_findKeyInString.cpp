#include <iostream>
#include <string>

using namespace std;

int findKey(string& str, int& n, char& key, int  i) {
    if (i >= n) {
        return -1;
    }

    if (str[i] == key) {
        cout << "found at index =>" << i << endl;
        return i;
    } 

    int ans = findKey(str, n, key, i + 1);
    return ans;
}

void countKey(string& str, int& n, char& key, int  i) {
    if (i >= n) {
        return ;
    }

    if (str[i] == key) {
        cout << "found at index =>" << i << endl;
    } 

    countKey(str, n, key, i + 1);
    
}

int main() {
    string str = "lovebabbar";
    int len = str.length();
    char key = 'b';
    int i = 0;

    cout << (findKey(str, len, key, i) ? "Found at index: " : "Not Found");

    cout << findKey(str, len, key, i) << endl;

    countKey(str, len, key, i) ;

    return 0;
}
