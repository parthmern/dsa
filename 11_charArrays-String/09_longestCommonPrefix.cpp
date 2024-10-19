#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    int curr = 0;
    string ans = "";

    while (true) {
        if (curr >= strs[0].length()) {
            break;
        }

        char temp = strs[0][curr];

        for (int i = 1; i < strs.size(); i++) {
            if (curr >= strs[i].length() || strs[i][curr] != temp) {
                return ans;
            }
        }

        ans += temp;
        curr++;
    }

    return ans;
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs) << endl; // Expected output: "fl"
    return 0;
}
