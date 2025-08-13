// https://www.geeksforgeeks.org/problems/cutted-segments1642/1 

class Solution {
  public:
  
    int ans = INT_MIN;
  
    void solve(int n, int x, int y, int z, int count){
        if(n==0){
            //cout << "ans "<< count << endl;
            if(ans<count){
                ans = count;
            }
        }
        
        if(n<0){
            return;
        }
        
        solve(n-x, x,y,z, count+1);
        solve(n-y, x,y,z,  count+1);
        solve(n-z, x,y,z,  count+1);
        
    }
  
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        
        
        solve(n,x,y,z,0);
        
        return ans;
        
    }
};