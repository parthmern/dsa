// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
// this is for binary tree so test fail ho jayenge

class Info{
    public:
    int maxVal;
    bool isHeap ;
    
    Info(){
        
    }
    Info(int maxi, bool ans){
        maxVal = maxi;
        isHeap = ans;
    }
};

class Solution {
  public:
  
    Info checkMaxHeap(Node* root){
        
        if(root==NULL) {
            Info temp(INT_MIN, true);
            return temp;
        }
        
        if(root->left == NULL && root->right==NULL){
            Info temp;
            temp.maxVal = root->data;
            temp.isHeap = true;
            return temp;
        }
        
        Info leftAns = checkMaxHeap(root->left);
        Info rightAns = checkMaxHeap(root->right);
        
        if((root->data > leftAns.maxVal) && (root->data > rightAns.maxVal) && leftAns.isHeap && rightAns.isHeap){
            Info ans;
            ans.maxVal = root->data;
            ans.isHeap = true;
            return ans;
        }else{
            Info ans;
            ans.maxVal = max(root->data, max(leftAns.maxVal, rightAns.maxVal));
            ans.isHeap = false;
            return ans;
        }
        
    }
 
  
    bool isHeap(Node* tree) {
        // code here
        Info ans = checkMaxHeap(tree);
        return ans.isHeap;
        
    }
};