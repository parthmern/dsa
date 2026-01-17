class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int r = 0;
        int c = matrix[0].length-1;

        while (r < matrix.length && c >= 0){
            
            int ele = matrix[r][c];
            if(ele==target) return true;
            if( ele > target ) c--;
            else r++;
        }

        return false;
    }
}