class Solution {

    private int[] prefixMax(int[] height){
        
        int[] ans = new int[height.length];
        
        int pre = -1;

        for(int i=0; i<height.length; i++){
            int ele = height[i];
            if(ele>pre){
                pre = ele;
            }
            ans[i] = pre;
        }

        System.out.println(Arrays.toString(ans));

        return ans;

    }

    private int[] suffixMax(int[] height){

        int n = height.length;

        int[] ans = new int[n];
        
        int suff = -1;

        for(int i=n-1; i>=0; i--){
            int ele = height[i];
            if(ele>suff) suff = ele;
            ans[i] = suff;
        }
        System.out.println(Arrays.toString(ans));

        return ans;
    }

    public int trap(int[] height) {

        int[] prefixMax = prefixMax(height);
        int[] suffixMax = suffixMax(height);

        int count = 0;

        for(int i=0; i<height.length; i++){

            int temp = Math.min(prefixMax[i], suffixMax[i]) - height[i];

            count = count + temp;

        }

        return count;
        
    }
}