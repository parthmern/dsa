class Solution {
    public String removeOuterParentheses(String s) {
        StringBuffer ans = new StringBuffer();

        int c = 0;
        for(int i=0; i<s.length(); i++){
            char ele = s.charAt(i);
            String str = Character.toString(ele);
            if(ele == ')') c--;
            if(c!=0) ans.append(ele);
            if(ele == '(') c++;

        }

        return ans.toString();

    }
}