// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

class Solution {
    public:
    
        void createMapping(vector<int>& inorder, map<int, int>& valueToIndexMap){
            for(int i=0; i<inorder.size(); i++){
                int element = inorder[i];
                int index = i;
                valueToIndexMap[element] = index;
            }
        }
    
        int searchInorder(vector<int>& inorder, int target){
            for(int i=0; i<inorder.size(); i++){
                if(inorder[i] == target){
                    return i;
                }
            }
            return -1;
        }
        
        TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preOrderIndex, int inorderStart, int inorderEnd, map<int, int>& valueToIndexMap){
            if(preOrderIndex>=preorder.size() || inorderStart>inorderEnd) return NULL;
    
            int ele = preorder[preOrderIndex];
            preOrderIndex++;
    
            TreeNode* root = new TreeNode(ele);
            
            // element search in inorder
            // int position = searchInorder(inorder, ele);
            int position = valueToIndexMap[ele];
            
            root->left = solve(preorder, inorder, preOrderIndex, inorderStart, position-1, valueToIndexMap);
            root->right = solve(preorder, inorder, preOrderIndex, position+1, inorderEnd, valueToIndexMap);
    
            return root;
        }
    
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int preIndex = 0;
            map<int, int> valueToIndexMap;
            createMapping(inorder, valueToIndexMap);
            return solve(preorder, inorder, preIndex, 0, inorder.size()-1, valueToIndexMap);
        }
    };