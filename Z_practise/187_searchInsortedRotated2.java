class Solution {

    private int pivotIndex(int[] arr) {

        int s = 0;
        int e = arr.length - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;
            System.out.println("s" + s + " e" + e);

            // conditon to add to handle duplicates
            if (arr[mid] == arr[e]) {
                e--;
            }
            else if (arr[mid] > arr[e]) {
                s = mid + 1;
            }
            else {
                e = mid;
            }
        }
        return s; // index of smallest element
    }

    private boolean bs(int[] arr, int target, int s, int e) {
        System.out.println("-s" + s + " e" + e);

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                return true;
            } 
            else if (arr[mid] < target) {
                s = mid + 1;
            } 
            else {
                e = mid - 1;
            }
        }
        return false;
    }

    public boolean search(int[] nums, int target) {

        int pi = pivotIndex(nums);
        System.out.println("pivot = " + pi);

        if (nums[pi] == target) return true;

          if (nums[0] == nums[pi] && nums[pi] == nums[nums.length - 1]) {
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] == target) return true;
            }
            return false;
        }

        if (pi > 0 && target >= nums[0] && target <= nums[pi - 1]) {
            return bs(nums, target, 0, pi - 1);
        }

        // right sorted part
        return bs(nums, target, pi, nums.length - 1);
    }
}
