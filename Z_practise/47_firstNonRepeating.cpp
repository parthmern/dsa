class Solution {
  public:
    char nonRepeatingChar(string &s) {
        vector<int> arr(26, 0);
        for(char ch : s){
            arr[ch - 'a']++;
        }
        
        for(char ch : s){
            if(arr[ch - 'a'] == 1)
                return ch;
        }
        
        return '$';
    }
};
