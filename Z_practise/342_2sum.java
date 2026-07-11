class Solution {
    public int[] twoSum(int[] nums, int target) {

        Pair[] arr = new Pair[nums.length];

        // Store value and original index
        for (int i = 0; i < nums.length; i++) {
            arr[i] = new Pair(nums[i], i);
        }

        // Sort by value of pair
        Arrays.sort(arr, (a, b) -> a.value - b.value);

        int left = 0;
        int right = arr.length - 1;

        while (left < right) {

            int sum = arr[left].value + arr[right].value;

            if (sum == target) {
                return new int[]{arr[left].index, arr[right].index};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return new int[]{};
    }
}

class Pair {
    int value;
    int index;

    Pair(int value, int index) {
        this.value = value;
        this.index = index;
    }
}