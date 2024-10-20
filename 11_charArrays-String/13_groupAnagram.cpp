// #include <iostream>
// #include <vector>
// #include <string>
// #include <map>
// #include <algorithm>
// using namespace std;

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
      
//         //#include <map>
//         map<string, vector<string>> mp;

//         for (auto str : strs) {
//             string s = str;
//             sort(s.begin(), s.end()); 
//             mp[s].push_back(str);    
//         }

//         vector<vector<string>> ans;
//         for (auto it = mp.begin(); it != mp.end(); it++) {
//             cout << "key: " << it->first << " | value: ";
//             for (const auto& str : it->second) {
//                 cout << str << " ";
//             }
//             cout << endl; 

//             ans.push_back(it->second);
//         }

//         return ans;
//     }
// };

// int main() {
//     // Example input
//     vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

//     // Create an instance of Solution
//     Solution solution;
//     vector<vector<string>> result = solution.groupAnagrams(strs);

//     // Output the result
//     cout << "Grouped Anagrams:" << endl;
//     for (const auto& group : result) {
//         for (const auto& word : group) {
//             cout << word << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }


// ======================================

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <array>
using namespace std;

std::array<int, 256> hashFunc(string s) {
    std::array<int, 256> hash = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i]]++;
    }
    return hash;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<std::array<int, 256>, vector<string>> mp;
    for (auto str : strs) {
        mp[hashFunc(str)].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans.push_back(it->second);
    }

    return ans;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);

    for (const auto& group : result) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
