class Solution {
    public String removeOuterParentheses(String s) {

        StringBuilder ans = new StringBuilder();

        int c = 0;

        for(int i=0; i<s.length(); i++){
            Character ch = s.charAt(i);
            boolean push = true;
            if(c == 0){
                push = false;
            }
            if(ch == '('){
               c++; 
            }
            if(ch == ')'){
                c--;
            }
            if(c == 0){
                push = false;
            }

            if(push){
                ans.append(ch);
            }
            
            
        }

        return ans.toString();

        
    }
}