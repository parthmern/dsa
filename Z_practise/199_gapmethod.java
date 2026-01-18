class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        int k = 0;
        for(int i=m; i<nums1.length; i++){
            nums1[i] = nums2[k];
            k++;
        }

        int gap = (m+n)/2;

        boolean one = true;

        while(gap>0){

            int i = 0;
            int j = i+gap;

            while(j<nums1.length){
                if(nums1[i]>nums1[j]){
                    int temp = nums1[i];
                    nums1[i] = nums1[j];
                    nums1[j] = temp;
                }
                i++;
                j++;
            }
            
            if(!one) break;

            if(gap==1){
                one = false;
            }else{
                gap = gap/2;
            }
        }

    }
}