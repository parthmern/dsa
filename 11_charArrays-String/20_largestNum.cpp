#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool myComp(string a, string b) {
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2;
}

string largestNumber(vector<int>& nums) {
    vector<string> snums;

    for (auto x : nums) {
        snums.push_back(to_string(x));
    }

    sort(snums.begin(), snums.end(), myComp);

    if (snums[0] == "0") {
        return "0";
    }

    string result = "";
    for (auto s : snums) {
        result += s;
    }

    return result;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    string result = largestNumber(nums);
    cout << result << endl;
    return 0;
}
