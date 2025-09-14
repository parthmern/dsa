/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
    
    Node* solve(vector<int>& nums, int inS, int inE){
        
        if(inS>inE){
            return NULL;
        }
        
        int mid = (inS+inE) / 2;
        Node* root = new Node(nums[mid]);
        
        root->left = solve(nums, inS, mid-1);
        root->right = solve(nums, mid+1, inE);
        
        return root;
        
    }
        
  
    Node* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);   
    }
};