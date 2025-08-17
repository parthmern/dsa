class Solution {
public:

    bool solve(string& s, string& p, int i, int j){

        if (i >= s.length() && j >= p.length()) return true;

        if (j >= p.length()) return false;

        if (i >= s.length()) {
            for (int k = j; k < p.length(); k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (s[i] == p[j] || p[j] == '?') {
            return solve(s, p, i + 1, j + 1);
        } 
        else if (p[j] == '*') {
            bool asNull = solve(s, p, i, j + 1);
            bool asOneConsumed = solve(s, p, i + 1, j);
            return asNull || asOneConsumed;
        }

        return false;
    }

    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};
