class Solution {
    public void setZeroes(int[][] matrix) {
        
        int rows = matrix.length;
        int cols = matrix[0].length;

        boolean rowTF = false;
        boolean colTF = false;

        for(int i=0; i<rows; i++){
            if(matrix[i][0] == 0){
                rowTF= true;
            }
        }

        for(int j=0; j<cols; j++){
            if(matrix[0][j] == 0){
                colTF = true;
            }
        }

        for(int i=1; i<rows; i++){
            for(int j=1; j<cols; j++){
                if(matrix[i][j] == 0){

                    // mark whole i to 0
                    // for(int col=0; col<cols; col++) matrix[i][col] = 0;
                    // for(int row=0; row<rows; row++) matrix[row][j] = 0;
                    
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                }
            }
        }

        for(int i=1; i<rows; i++){
            if(matrix[i][0] == 0){
                for(int col=1; col<cols; col++) matrix[i][col] = 0;
            }
        }

        for(int j=1; j<cols; j++){
            if(matrix[0][j] == 0){
                for(int row=1; row<rows; row++) matrix[row][j] = 0;
            }
        }

        if(rowTF){
            for(int row=0; row<rows; row++) matrix[row][0] = 0;
        }


        if(colTF){
          for(int col=0; col<cols; col++) matrix[0][col] = 0;
        }

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                System.out.print(matrix[i][j]+ " ");
            }
            System.out.println("");
        }

    }
}