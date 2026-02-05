class Solution {
    
    private static int priority(char ch){
        
        if(ch == '^') return 3;
        if(ch == '*' || ch == '/') return 2;
        if(ch == '+' || ch == '-') return 1;
        return -1;
        
    }
    
    public static String infixToPostfix(String s) {
        // code here
        
        Stack<Character> st = new Stack<>();
        StringBuilder ans = new StringBuilder();
        
        for( int i=0; i<s.length(); i++){
            
            char ch = s.charAt(i);
            
            if(Character.isLetter(ch) || Character.isDigit(ch)){
                ans.append(ch);
            }else{
                
                if(ch=='('){
                    st.push('(');
                }else if(ch==')'){
                    while (!st.empty() && st.peek()!='('){
                        ans.append(st.peek());
                        st.pop();
                    }
                    st.pop();
                }else{
                    // while(!st.empty() && priority(ch) <= priority(st.peek())) -- fail for some test
                    // Edge: For ^ you should NOT pop when precedence is equal.
                    while(
                        !st.empty() &&
                        (
                            priority(ch) < priority(st.peek()) ||
                            (priority(ch) == priority(st.peek()) && ch != '^')
                        )
                    )
                    {
                        ans.append(st.peek());
                        st.pop();
                    }
                    st.push(ch);
                }
    
            }
            
        }
        
        while (!st.empty()){
            ans.append(st.peek());
            st.pop();
        }
        
        return ans.toString();
    }
}