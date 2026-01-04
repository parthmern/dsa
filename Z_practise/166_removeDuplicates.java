class Solution {
    public int removeDuplicates(int[] nums) {
        ArrayList<Integer> arr = new ArrayList<>();
        int i = 0;
        int j = 0;

        while( i < nums.length ){
            
            
            while( nums[i] == nums[j] ){
                j++;
                if(j >= nums.length ) break;
            }

            arr.add(nums[i]);
            i=j;
        }
        
        System.out.println("arr" + arr);

        int index = 0;
        for(int ele: arr){
            nums[index++] = ele;
        }

        return arr.size();

    }
}