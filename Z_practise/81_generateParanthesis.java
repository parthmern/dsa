class Solution {

    public List<String> ans = new ArrayList<>();

    public void helper(int open, int close, String temp){

        if( open<=0 && close <= 0 ){
            System.out.println( "temp" + temp );
            ans.add(temp);
            return;
        }

        // add open br
        if(open>0){
            helper(open-1, close, temp + "(");
        }

        // add close br
        if( open < close && close>0 ){
          
            helper(open, close - 1,temp + ")" );
        }

    }

    public List<String> generateParenthesis(int n) {

        helper(n, n, "");
        return  ans;
    }
}