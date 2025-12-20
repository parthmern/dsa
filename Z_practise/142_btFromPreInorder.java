/*
class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    
    public static int preI = 0;
    
    public static int findIndex(int inorder[], int ele){
        int ans = -1;
        
        for(int i=0; i<inorder.length; i++){
            if(inorder[i] == ele) return i;
        }
        
        return ans;
    }
    
    public static Node helper(int inorder[], int preorder[], int s, int e){
        
        if(preI >= preorder.length || s>e) return null;
        
        int preOrderEle = preorder[preI];
        //System.out.println("making node for" + inorderEle);
        Node root = new Node(preOrderEle);
        
        int mid = findIndex(inorder, preOrderEle);
        
        preI++;
        
        root.left = helper( inorder, preorder, s, mid-1);
        // if(root.left == null) preI++;
        root.right = helper(inorder, preorder, mid+1, e);
    
        
        return root;
        
    }
    
    public static Node buildTree(int inorder[], int preorder[]) {
        // code here
        preI = 0;  
        
        return helper(inorder, preorder, 0 , inorder.length-1);
    }
}