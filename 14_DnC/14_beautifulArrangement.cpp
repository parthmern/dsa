#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void counterHelper(vector<int>& v, int& n, int& ans, int currNum) {
        // Base case
        if (currNum == n + 1) {
            ans++;
            for (int i = 1; i <= n; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
            return;
        }

        // Try placing `currNum` in each valid position
        for (int i = 1; i <= n; i++) {
            if (v[i] == 0 && (currNum % i == 0 || i % currNum == 0)) {
                v[i] = currNum; // Place `currNum`
                counterHelper(v, n, ans, currNum + 1); // Recurse for the next number
                v[i] = 0; // Backtrack
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v(n + 1, 0); // Vector to track used positions (1-based indexing)
        int ans = 0;            // To count valid arrangements
        counterHelper(v, n, ans, 1);
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 3;
    cout << "Valid arrangements:" << endl;
    int result = sol.countArrangement(n);
    cout << "Number of valid arrangements: " << result << endl;
    return 0;
}
