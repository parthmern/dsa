class Solution {

    private void swap(int[][] arr, int i, int j){
        int temp = arr[i][j];
        arr[i][j] = arr[j][i];
        arr[j][i] = temp;
    }

    public void rotate(int[][] matrix) {
        
        int n = matrix.length;

        for(int i=1; i<n; i++){

            for(int j=0; j<i; j++){
                swap(matrix, i, j);
            }

        }

        // row reverse
        for(int i=0; i<n; i++){
            int s = 0;
            int e = n-1;
            while(s<e){
                System.out.print("s" + s + " e " + e);
                int temp = matrix[i][s];
                matrix[i][s] = matrix[i][e];
                matrix[i][e] = temp;
                s++;
                e--;
            }
            System.out.println("");
        }


    }
}