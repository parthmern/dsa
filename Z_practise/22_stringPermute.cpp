class Solution {
  public:
  
  
    vector<string> ans;
  
    void solve(string s, int i){
        if(i>=s.length()){
            ans.push_back(s);
        }
        
        for(int j=i; j<s.length(); j++){
            swap( s[i], s[j] );
            solve( s,i+1);
            swap( s[i], s[j] );
        }
        
    }
  
    vector<string> findPermutation(string &s) {
        solve(s,0);
        return ans;
    }
};
