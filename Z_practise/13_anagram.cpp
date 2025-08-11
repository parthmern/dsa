class Solution {
public:
    bool isAnagram(string s, string t) {
        int stringA[256] = {0};
        int stringB[256] = {0};
        for (int i = 0; i < s.length(); i++) {
            char temp = s[i];
            int index = (int)s[i];
            stringA[index] = stringA[index] + 1;
        }
        for (int i = 0; i < t.length(); i++) {
            char temp = t[i];
            int index = (int)t[i];
            stringB[index] = stringB[index] + 1;
        }
        int flag = true;
        for (int j = 0; j < 256; j++) {
            if (s.length() > t.length()) {
                if (stringA[j] != 0) {
                    if (stringA[j] != stringB[j]) {
                        cout << "a " << stringA[j] << " b " << stringB[j]
                             << endl;
                        flag = false;
                        break;
                    }
                }
            }else{
                 if (stringB[j] != 0) {
                    if (stringA[j] != stringB[j]) {
                        cout << "a " << stringA[j] << " b " << stringB[j]
                             << endl;
                        flag = false;
                        break;
                    }
                }
            }
        }
        return flag;
    }
};