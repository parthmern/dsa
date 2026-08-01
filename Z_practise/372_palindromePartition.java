class Solution {

     List<List<String>> ans  = new ArrayList<>();

    private boolean isPalindrome(String s, int l , int r) {

        while (l < r) {
            if (s.charAt(l) != s.charAt(r))
                return false;
            l++;
            r--;
        }

        return true;
    }

    private void solve(String s, int idx, List<String> temp){

        if(idx == s.length()){
            ans.add(new ArrayList<>(temp));
            return;
        }

        for(int i=idx; i<s.length(); i++){
            String part = s.substring(idx, i+1);
            boolean isPal = isPalindrome(s, idx, i);
            if(isPal){
                temp.add(part);
                solve(s, i+1, temp);
                temp.remove(temp.size()-1);
            }
        }

    }

    public List<List<String>> partition(String s) {
        ans.clear();
        solve(s,0, new ArrayList<>());
        return ans;
    }
}