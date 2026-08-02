class Solution {

    private void solve(int[] arr, int[] ans){

        Stack<Integer> st = new Stack<>();
        st.push(-1);

        for(int i=arr.length-1; i>=0; i--){

            int ele = arr[i];

            while(st.peek() != -1 && st.peek() < ele){
                st.pop();
            }
            ans[i] = st.peek();
            st.push(ele);
        }

    }

    public int[] nextGreaterElement(int[] nums1, int[] nums2) {

        //ArrayList<Integer> ans = new ArrayList<>(nums2.length);
        int[] anss = new int[nums2.length];
        solve(nums2, anss);

        System.out.println("ans => " + Arrays.toString(anss));

        int[] ans = new int[nums1.length];
        for(int i=0; i< nums1.length; i++){
            int ele = nums1[i];

            for(int j=0; j<nums2.length; j++){
                if(ele == nums2[j]){
                    ans[i] = anss[j];
                }
            }

        }

        return ans;

        
    }
}