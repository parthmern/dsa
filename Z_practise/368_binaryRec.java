class Solution {
    
    ArrayList<String> ans = new ArrayList<>();
    
    private void solve(int i, int n, String temp){
        if(i==n){
            ans.add(temp);
            return;
        }
        solve(i+1, n, temp+"0");
        solve(i+1, n, temp+"1");
    }
    
    public ArrayList<String> binstr(int n) {
        // code here
        ans.clear();
        solve(0, n, "");
        return ans;
    
    }
}
