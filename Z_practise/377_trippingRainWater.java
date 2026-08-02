class Solution {

    private void prefixMax(int[] arr, int[] prefix){

        prefix[0] = arr[0];

        for(int i=1; i<arr.length; i++){
            prefix[i] = Math.max(prefix[i-1], arr[i]);
        }

    }

    private void suffixMax(int[] arr, int[] suffix){

        suffix[suffix.length-1] = arr[arr.length-1];

        for(int i=arr.length-2; i>=0; i--){
            suffix[i] = Math.max(suffix[i+1], arr[i]);
        }

    }

    public int trap(int[] height) {

        int n = height.length;
        int[] prefix = new int[n];
        int[] suffix = new int[n];

        prefixMax(height, prefix);
        suffixMax(height, suffix);

        int ans = 0;
        for(int i=0; i<n; i++){
            ans = ans + Math.min(prefix[i], suffix[i]) - height[i];
        }

        return ans;
        
    }
}