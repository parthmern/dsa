class Solution {

    private int pivotIndex(int[] arr, int s, int e) {

        // array not rotated
        if (arr[s] <= arr[e])
            return -1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] >= arr[0]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s; // index of smallest element
    }

    private int bs(int[] arr, int s, int e, int target) {
        System.out.println("s" + s + "e" + e);
        if (s > e)
            return -1;

        int mid = (s + e) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target) {
            return bs(arr, s, mid - 1, target);
        } else {
            return bs(arr, mid + 1, e, target);
        }

    }

    public int search(int[] nums, int target) {

        // find pivot ele

        int ans = pivotIndex(nums, 0, nums.length - 1);
        System.out.println("ans" + ans);

        if (ans == -1) {
            return bs(nums, 0, nums.length - 1, target);
        } else if (nums[0] == target) {
            return 0;
        } else if (nums[ans] == target) {
            return ans;
        }
        if (target >= nums[0] && target <= nums[ans - 1]) {
            return bs(nums, 0, ans - 1, target);
        } else {
            return bs(nums, ans, nums.length - 1, target);
        }

    }
}