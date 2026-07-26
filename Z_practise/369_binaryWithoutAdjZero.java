class Solution {
        
    ArrayList<String> ans = new ArrayList<>();
    
    private void solve(int i, int n, String temp){
        if(i==n){
            ans.add(temp);
            return;
        }
        if(temp.length() < 1){
            solve(i+1, n, temp+"0");
        }else{
            if(temp.charAt(i-1) != '0'){
                solve(i+1, n, temp+"0");
            }
        }
        solve(i+1, n, temp+"1");
    }

    public List<String> validStrings(int n) {
        ans.clear();
        solve(0, n, "");
        return ans;
    }
}