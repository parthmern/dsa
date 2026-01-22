class Solution {
    
    private void rec(String num, int i, ArrayList<String> ans){
        if(i==0){
            ans.add(num);
            return;
        }
        
        rec(num+"0", i-1, ans);
        rec(num+"1", i-1, ans);
    }
    
    public ArrayList<String> binstr(int n) {
        // code here
        ArrayList<String> ans = new ArrayList<>();
        rec("", n, ans);
        return ans;
    }
}
