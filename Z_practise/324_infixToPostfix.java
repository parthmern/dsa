class Solution {
    
    private static int priority(char ch){
        
        if(ch == '^') return 3;
        if(ch == '*' || ch == '/') return 2;
        if(ch == '+' || ch == '-') return 1;
        return -1;
        
    }
    
    public static String infixToPrefix(String s){
    
        // Step 1: reverse + swap brackets
        StringBuilder rev = new StringBuilder();
        for(int i=s.length()-1;i>=0;i--){
            char ch = s.charAt(i);
    
            if(ch=='(') rev.append(')');
            else if(ch==')') rev.append('(');
            else rev.append(ch);
        }
    
        Stack<Character> st = new Stack<>();
        StringBuilder ans = new StringBuilder();
    
        for(int i=0;i<rev.length();i++){
    
            char ch = rev.charAt(i);
    
            if(Character.isLetterOrDigit(ch)){
                ans.append(ch);
            }
            else{
                if(ch=='('){
                    st.push(ch);
                }
                else if(ch==')'){
                    while(!st.empty() && st.peek()!='('){
                        ans.append(st.pop());
                    }
                    st.pop();
                }
                else if(ch=='^'){
                    while(!st.empty() && priority(ch) <= priority(st.peek())){
                        ans.append(st.peek());
                        st.pop();
                    }
                    st.push(ch);
                }
                else{
                    
                    while(!st.empty() && priority(ch) < priority(st.peek())){
                        ans.append(st.pop());
                    }
                     st.push(ch);
                }
            }
        }
    
        while(!st.empty()){
            ans.append(st.pop());
        }
    
        // Step 3 reverse answer
        return ans.reverse().toString();
    }

}