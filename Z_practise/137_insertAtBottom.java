class Solution {
    
    private static void insertAtBottom(Stack<Integer> st, int ele){
        
        
        
        if(st.empty()){
            st.push(ele);
            // System.out.println("inserting bottom" + ele);
            return;
        }
        
        int top = st.pop();
        insertAtBottom(st, ele);
        st.push(top);
        
        return;
    }
    
    private static void helper(Stack<Integer> st, int size, int i){
        
        if( i == size) return;
        
        int top = st.pop();
        helper(st, size, i+1);
        insertAtBottom(st, top);
        
    }
    
    public static void reverseStack(Stack<Integer> st) {
        // code here
        helper(st, st.size(), 0);
        
    }
}
