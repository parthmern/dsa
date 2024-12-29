#include <iostream>
#include <string>
using namespace std;

void removeOcc(string &s, const string &part) {
    int found = s.find(part);

    if (found != string::npos) {
        // Part string is found
        string leftPart = s.substr(0, found);
        string rightPart = s.substr(found + part.size());
        s = leftPart + rightPart;

        // s.erase(found, part.length());   // another way

        // Recursively call removeOcc to remove further occurrences
        removeOcc(s, part);
    }else{
        return;
    }
}

// void removeOcc(string &s, const string &part){

//     int findIndex = s.find(part);

//     if( findIndex != string::npos ){
//         s.erase( findIndex, part.length());
//         removeOcc(s,part);
//     }else{
//         return ;
//     }

// }

string removeAllOccurrences(string s, const string &part) {
    removeOcc(s, part);
    return s;
}

int main() {
    string s = "daabcbaabcbc";
    string part = "abc";

    cout << "Original string: " << s << endl;
    string result = removeAllOccurrences(s, part);
    cout << "Modified string: " << result << endl;

    return 0;
}
