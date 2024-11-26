#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(vector<string> &ans, int n, int open, int close, string output){
    // base case
    if( open<=0 && close<=0 ){
        ans.push_back(output);
        return;
    }

    // rr
    // include open bracket
    if(open>0){
        // output.push_back('(');
        // solve(ans, n, open-1, close, output);
        // output.pop_back();  // backtracking

        solve(ans, n, open-1, close, output + '(');
    }

    // include close bracket
    if(open<close){
        // output.push_back(')');
        // solve(ans, n, open, close-1, output);
        // output.pop_back();  // backtracking

        solve(ans, n, open, close-1, output + ')' );
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    int open = n;
    int close = n;

    string output = "";

    solve(ans, n, open, close, output);

    return ans;
}

int main() {
    int n = 2;
    vector<string> result = generateParenthesis(n);

    cout << "Generated Parentheses Combinations:\n";
    for(const string &s : result) {
        cout << s << endl;
    }

    return 0;
}
