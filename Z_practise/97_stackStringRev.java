class Solution {
    public void reverseString(char[] s) {
    Stack<Character> st = new Stack<>();
       for(char ele : s){
            st.push(ele);
        }
        
        int i = 0;
        while(!st.empty()){
            s[i++] = st.peek();
            st.pop();
        }
        
    }
}