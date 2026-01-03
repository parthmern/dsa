class Solution {

    private void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public void sortColors(int[] nums) {
        int totalRounds = nums.length;
        for(int i=0; i<totalRounds; i++){

            int a = 0;
            int b = 1;
            
            while(b < totalRounds){
                
                if(nums[a] > nums[b]){
                    System.out.println("b" + b);
                    swap(nums, a, b);
                }
                a++;
                b++;                
            }

           for (int x : nums) {
                System.out.print(x + " ");
            }
            System.out.println("");

        }
    }
}

// bubble sort
// O(n^2)