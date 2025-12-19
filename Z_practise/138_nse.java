class Solution {
    
    private static void helper(Stack<Integer> st, int[] arr, ArrayList<Integer> ans){
        
        for( int i=arr.length -1 ; i>=0; i-- ){
            int ele = arr[i];
            int top = st.peek();
            
            while(top>=ele){
                st.pop();
                top = st.peek();
            }
            
            ans.set(i, top);
            st.push(ele);
            //System.out.println("settning" + i  + " " + top);
            
        }
        
    }
    
    static ArrayList<Integer> nextSmallerEle(int[] arr) {
        // code here
        
        ArrayList<Integer> ans = new ArrayList<>(arr.length);
        
        for(int ele: arr) ans.add(-1);
        
        Stack<Integer> st = new Stack<>();
        st.push(-1);
        
        helper(st, arr, ans);
        
        return ans;
    }
}