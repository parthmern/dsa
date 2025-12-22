
class Node{
    
    int val;
    int row;
    int col;
    
    Node(int v, int r ,int c){
        val =v;
        row =r;
        col =c;
    }
    
}


class Solution {
    
    
    
    public ArrayList<Integer> mergeArrays(int[][] mat) {
        // Code here
        
        ArrayList<Integer> ans = new ArrayList<>();        
        
        PriorityQueue<Node> minHeap = new PriorityQueue<>((a, b) -> a.val - b.val);
        
        for( int i=0; i<mat.length; i++ ){
            int col=0;
            minHeap.add( new Node(mat[i][col] , i, col) );
        }
        
        while( !minHeap.isEmpty() ){
            
            Node ele = minHeap.remove();
            
            ans.add( ele.val );
            
            if(ele.col+1 < mat[ele.row].length ){
                minHeap.add( new Node( mat[ele.row][ele.col+1], ele.row, ele.col+1 ) );    
            }
            
        }
        
        return ans;
        
    }
}