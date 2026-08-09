class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {

        List<Integer> ans = new ArrayList<>();
        Stack<TreeNode> st = new Stack<>();

        TreeNode curr = root;

        while (curr != null || !st.isEmpty()) {

            // Push all left nodes
            while (curr != null) {
                st.push(curr);
                curr = curr.left;
            }

            // Get leftmost node
            TreeNode top = st.pop();

            ans.add(top.val);

            // Move to right subtree
            curr = top.right;
        }

        return ans;
    }
}