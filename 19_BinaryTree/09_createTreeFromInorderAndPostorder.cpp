
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
    public:
        void createMapping(vector<int>& inorder, map<int, int>& valueToIndexMap) {
            for (int i = 0; i < inorder.size(); i++) {
                int element = inorder[i];
                int index = i;
                valueToIndexMap[element] = index;
            }
        }
    
        TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& postOrderIndex, int inorderStart, int inorderEnd, map<int, int>& valueToIndexMap) {
            if (postOrderIndex < 0 || inorderStart > inorderEnd)
                return NULL;
    
            int ele = postorder[postOrderIndex];
            postOrderIndex--;
    
            TreeNode* root = new TreeNode(ele);
    
            // element search in inorder
            int position = valueToIndexMap[ele];
    
            // right first
            root->right = solve(inorder, postorder, postOrderIndex, position + 1, inorderEnd, valueToIndexMap);
            root->left = solve(inorder, postorder, postOrderIndex, inorderStart, position - 1, valueToIndexMap);
        
            return root;
        }
    
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            int postIndex = postorder.size()-1;
            map<int, int> valueToIndexMap;
            createMapping(inorder, valueToIndexMap);
            return solve(inorder, postorder, postIndex, 0, inorder.size()-1, valueToIndexMap);
        }
    };