#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(vector<string> &ans, int index, string output, string digits, vector<string> mapping) {
    // base case
    if (index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    // rr
    int digit = digits[index] - '0';    // int convert
    string value = mapping[digit];

    for (int i = 0; i < value.length(); i++) {
        char ch = value[i];
        output.push_back(ch);
        solve(ans, index + 1, output, digits, mapping);
        output.pop_back();  // backtracking
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.length() == 0) {
        return ans;
    }

    int index = 0;
    string output = "";

    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    solve(ans, index, output, digits, mapping);

    return ans;
}

int main() {
    string digits = "29";

    vector<string> result = letterCombinations(digits);

    cout << "Possible letter combinations are:\n";
    for (const string &comb : result) {
        cout << comb << endl;
    }

    return 0;
}
