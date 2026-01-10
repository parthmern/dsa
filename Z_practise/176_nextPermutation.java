class Solution {

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public void nextPermutation(int[] nums) {

        int breakIndex = -1;

        // find first ele from right which is not in decending order
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                breakIndex = i;
                break;
            }
        }

        if (breakIndex == -1) {
            // reverse whole 
            int i = 0;
            int j = nums.length - 1;
            while (i < j) {
                swap(nums, i, j);
                i++;
                j--;
            }
        } else {
            int smallestGreaterIndex = 0;
            // swap mid and largest ele
            for (int i = nums.length - 1; i > breakIndex; i--) {
                if (nums[i] > nums[breakIndex]) {
                    smallestGreaterIndex = i;
                    break;
                }
            }

            swap(nums, smallestGreaterIndex, breakIndex);

            int i = breakIndex + 1;
            int j = nums.length - 1;

            System.out.println("i,j" + i + " " + j);

            System.out.println(Arrays.toString(nums));

            while (i <= j) {
                swap(nums, i, j);
                i++;
                j--;
            }
        }

    }
}