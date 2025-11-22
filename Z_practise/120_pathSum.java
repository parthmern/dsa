class Solution {

    int ans = 0;

    void targetSumFuncRoot(TreeNode root, long currSum, long ts) {
        if (root == null) return;

        if (currSum + root.val == ts) {
            ans++;
        }

        targetSumFuncRoot(root.left, currSum + root.val, ts);
        targetSumFuncRoot(root.right, currSum + root.val, ts);
    }

    public int pathSum(TreeNode root, long targetSum) {
        long sum = 0;

        if (root != null) {
            targetSumFuncRoot(root, sum, targetSum);
            pathSum(root.left, targetSum);
            pathSum(root.right, targetSum);
        }

        return ans;
    }
}
