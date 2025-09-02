class Solution {
  public: 
  
    void solve(stack<int>& s, int size){
        
       if (s.size() == (size/2) + (size % 2 == 0 ? 0 : 1)) {
            s.pop();
            return;
        }

        
        int temp = s.top();
        s.pop();
        solve(s, size);
        s.push(temp);
        
    }
    
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        solve(s, s.size());
    }
};