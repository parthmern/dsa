class Solution {
    public static ArrayList<Integer> prevSmaller(int[] arr) {
        // code here
        
        ArrayList<Integer> ans = new ArrayList<>();
        Stack<Integer> st = new Stack<>();
        
        st.push(-1);
        
        for(int i=0; i<arr.length; i++){
            
            int curr = arr[i];
            
            while( !st.empty() && st.peek() >= curr){
                st.pop();
            }
            
            ans.add( st.peek() );
            
            st.push(curr);
        }
        
        return ans;
        
    }
}