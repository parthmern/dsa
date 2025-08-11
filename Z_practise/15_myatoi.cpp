class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int multiWith = 1;
        int num = 0;
        while (s[i] == ' ') {
            i++;
        }

        if (s[i] == '-') {
            multiWith = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        cout << "i " << i << endl;

        while (isdigit(s[i]) && (!isalpha(s[i]))) {
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
                return multiWith == -1 ? INT_MIN : INT_MAX;
            }
            char ch = s[i];
            num = num * 10 + (ch - '0');
            i++;
        }

        return num * multiWith;
    }
};