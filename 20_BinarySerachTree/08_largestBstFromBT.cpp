// https://www.geeksforgeeks.org/problems/largest-bst/1

class NodeData{
    public:
        int size;
        int min;
        int max;
        bool validBst;
        
        NodeData(){};
        
        NodeData(int s, int maxi, int mini, bool valid){
            size = s;
            max=maxi;
            min=mini;
            validBst=valid;
        };
};

class Solution {
  public:
  
    NodeData solve(Node* root, int &ans){
        
        if(root==NULL){
            NodeData temp(0, INT_MIN, INT_MAX, true);
            return temp;
        }
        
        NodeData leftAns = solve(root->left, ans);
        NodeData rightAns = solve(root->right, ans);
        
        // checking
        NodeData currNodeKaAns;
        currNodeKaAns.size = leftAns.size+rightAns.size+1;
        currNodeKaAns.max = max(root->data, rightAns.max);
        currNodeKaAns.min = min(root->data, leftAns.min);
        currNodeKaAns.validBst = leftAns.validBst && rightAns.validBst && (root->data > leftAns.max && root->data < rightAns.min);
        
        if(currNodeKaAns.validBst){
            ans = max(ans, currNodeKaAns.size);
        }
        
        return currNodeKaAns;
    }
  
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        // Your code here
        int ans = -1;
        solve(root, ans);
        return ans;
    }
};