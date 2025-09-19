// https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/ 
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool nullSeen = false;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == NULL) {
                nullSeen = true;  // once we see NULL, mark it
            } else {
                if (nullSeen) {
                    // If we already saw NULL and now see a node → not complete
                    return false;
                }
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    } 
};
