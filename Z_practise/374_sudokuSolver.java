class Solution {

    private boolean isSafe(char[][] arr, int i, int j, char num){

        int n = arr.length; // row
        int m = arr[0].length; // col

        for(int row=0; row<n; row++){
            if(num==arr[row][j]) return false;
        }

        for(int col=0; col<m; col++){
            if(num==arr[i][col]) return false;
        }
        
        // 3x3
        for(int k=0; k<n; k++){
            int row = 3*(i/3)+k/3;
            int col = 3*(j/3)+k%3;
            if(arr[row][col]==num) return false;
        }

        return true;

    }

    private boolean solve(char[][] arr){

        int n = arr.length;
        int m = arr[0].length;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char ch = arr[i][j];
                if(ch == '.'){
                    for(int num=1; num<=9; num++){
                        char digit = (char) (num + '0');
                        boolean isSafeAns = isSafe(arr, i, j, digit);
                        if(isSafeAns){
                            arr[i][j] = digit;
                            boolean ans = solve(arr);
                            if(ans) return true;
                            arr[i][j] = '.';
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }

    public void solveSudoku(char[][] board) {

        solve(board);
        
    }
}