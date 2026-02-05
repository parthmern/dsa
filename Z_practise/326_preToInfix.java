// User function Template for Java

class Solution {
    
    static String preToInfix(String pre_exp) {
        Stack<String> st = new Stack<>();

        // right --> left
        for (int i = exp.length() - 1; i >= 0; i--) {
            char ch = exp.charAt(i);

            if (Character.isLetterOrDigit(ch)) {
                st.push(ch + "");
            } else { 
                String op1 = st.pop(); // first operand (right)
                String op2 = st.pop(); // second operand (left)
                String expr = "(" + op1 + ch + op2 + ")";
                st.push(expr);
            }
        }

        return st.peek();
        
    }
}
