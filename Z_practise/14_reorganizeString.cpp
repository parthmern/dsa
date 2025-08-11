class Solution {
public:
    string reorganizeString(string s) {

        string res(s.length(), ' ');

        // making map table
        int map[256] = {0};
        for (int i = 0; i < s.length(); i++) {
            int ch = s[i];
            int index = (int)ch;
            map[index] = map[index] + 1;
        }

        // find max
        int max = 0;
        int maxLetterindex = 0;
        for (int i = 0; i < 256; i++) {
            if (map[i] > max) {
                max = map[i];
                maxLetterindex = i;
            }
        }

        // match condition
        if (max > (s.length() + 1) / 2) {
            return "";
        }

        cout << "max " << max << "maxLetterindex " << maxLetterindex << endl;

        // else do whole logic
        // a) adjusting  x,_,x,_,x,_
        int seetingIndex = 0;
        char maxLetter = maxLetterindex;
        cout << " maxLetter " << maxLetter << endl;
        while (max > 0 && seetingIndex < res.size()) {
            res[seetingIndex] = maxLetter;
            map[maxLetterindex]--;
            max--;
            seetingIndex = seetingIndex + 2;
        }

        cout << " mpa " << map[maxLetterindex] << endl;

        for (int i = 0; i < 256; i++) {
            while (map[i]-- > 0) {
                if (seetingIndex >= res.size()) {
                    seetingIndex = 1; 
                }
                if (seetingIndex < res.size()) {
                    res[seetingIndex] = (char)(i);
                }
                seetingIndex += 2;
            }
        }

        return res;
    }
};