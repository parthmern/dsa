class Solution {
public:

    bool isPalindrome(string s, int i, int j){
        cout << "called for start" << i << j << endl;
        while(i<j){
            if( s[i] != s[j] ){
                cout << "called for" << i << j << endl;
                return false;
            }
            
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        
        int i = 0;
        int j = s.length() - 1;

        while(i<j){
            if( s[i] != s[j] ){
                cout << "ne for called for " << i << j << endl;
                int removeI = isPalindrome(s, i+1, j);
                int removeJ = isPalindrome(s, i, j-1);
                return removeI | removeJ ;
            }
            i++;
            j--;
        }

        return true;
    }
};