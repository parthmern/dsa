class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {

        List<Integer> ans = new ArrayList<>();
        Stack<TreeNode> st = new Stack<>();
        Stack<Integer> visited = new Stack<>();

        if(root == null) return ans;
        st.push(root);
        visited.push(0);
        

        while (!st.isEmpty()) {

            // 1st time visit
            // inorder - LNR

            TreeNode top = st.pop();
            int visitTime = visited.pop();

            if(visitTime == 1){
                ans.add(top.val);
                continue;
            }

            if(top.right != null){
                st.push(top.right);
                visited.push(0);
            }

            st.push(top);
            visited.push(1);

            if(top.left != null){
                st.push(top.left);
                visited.push(0);
            }
            
        }

        return ans;
    }
}