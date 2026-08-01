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
        
        StringBuilder str = new StringBuilder();
        
        
        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            
            if (Character.isLetterOrDigit(ch)) {
                str.append(ch);
            }
            else if(ch == '('){
                st.push(ch);
            }else if(ch == ')'){
                while(!st.isEmpty() && st.peek() != '('){
                    str.append(st.pop());
                }
                st.pop();
            }else{

                 while (!st.isEmpty() &&
                        (priority(st.peek()) > priority(ch) ||
                        (priority(st.peek()) == priority(ch) && ch != '^'))) {

                    str.append(st.pop());
                }

                st.push(ch);
            }
        }
        
        while (!st.isEmpty()) {
            str.append(st.pop());
        }
        
        return str.toString();
        
    }
}