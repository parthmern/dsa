// User function Template for Java
class Solution {
    
    public void helper(Stack<Integer> st, int ele){
        
        if( st.empty() ){
            st.push(ele);
            return;
        }
        
        int peek = st.peek();
        st.pop();
        helper(st, ele);
        st.push(peek);
        
        return;
        
    }
    
    public Stack<Integer> insertAtBottom(Stack<Integer> st, int x) {
        
        helper(st, x);
        return st;
        
    }
}