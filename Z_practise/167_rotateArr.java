class Solution {

   public void rotate(int[] nums, int k) {
    int n = nums.length;
    k = k % n;

    if (k == 0) return;

    System.out.println("k=>" + k + " " + n);

    shiftingLogic(nums, k);
}

private void shiftingLogic(int[] nums, int k) {
    int n = nums.length;
    int[] temp = new int[k];

    // Store last k elements
    for (int i = 0; i < k; i++) {
        temp[i] = nums[n - k + i];
    }

    // Shift remaining elements to the right
    for (int i = n - 1; i >= k; i--) {
        nums[i] = nums[i - k];
    }

    // Copy temp to first k positions
    for (int i = 0; i < k; i++) {
        nums[i] = temp[i];
    }
}

}