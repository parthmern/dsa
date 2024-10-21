#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        char prev = chars[0];
        int count = 1;

        for (int i = 1; i < chars.size(); i++) {
            cout << "Now on -> " << chars[i] << endl;

            if (prev == chars[i]) {
                count++;
            } else {
                chars[index++] = prev;

                if (count > 1) {
                    int start = index;
                    while (count) {
                        chars[index++] = (count % 10) + '0';
                        count /= 10;
                    }
                    reverse(chars.begin() + start, chars.begin() + index);
                }

                prev = chars[i];
                count = 1;
            }
        }

        chars[index++] = prev;
        if (count > 1) {
            int start = index;
            while (count) {
                chars[index++] = (count % 10) + '0';
                count /= 10;
            }
            reverse(chars.begin() + start, chars.begin() + index);

            // std::string countStr = std::to_string(count);
            // for (char c : countStr) {
            //     chars[index++] = c;
            // }
            
        }

        return index;
    }
};

int main() {
    vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    Solution solution;
    int newLength = solution.compress(chars);

    cout << "Compressed characters: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i];
    }
    cout << endl;

    cout << "New length: " << newLength << endl;

    return 0;
}
