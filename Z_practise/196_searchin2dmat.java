class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        // log (m*n) search in sorted matrix means bs
        int rows = matrix.length;
        int cols = matrix[0].length;

        int len = cols*rows;

        int s = 0;
        int e = len-1;

        while(s<=e){

            int mid = (s+e)/2;
            System.out.println("mid"+mid+ "row"+(mid/cols) +"tr"+rows+"| col"+(mid%cols)+"tc " +cols);
            int row = mid/cols;
            int col = mid%cols;
            if( (row >= rows) || (col >= cols) ) continue;
            int ele = matrix[mid/cols][mid%cols];

            if(ele==target) return true;
            
            if(ele<target) s = mid+1;
            else e = mid-1;

        }

        return false;

    }
}