class Solution {

    static boolean ans = false;

    private void spread(boolean[][] isVisited, char[][] arr, String word, int i, int j, int idx){

        int n = arr.length;
        int m = arr[0].length;

        //System.out.println("idx " + idx + " [i][j] : " + i + " "+ j);
        
        if(idx == word.length()){
            //System.out.println("true " + idx + " [i][j] : " + i + " "+ j);
            ans = true;
            return;
        }
        
        char nextCh = word.charAt(idx);

        // left
        if(j-1>=0 && isVisited[i][j-1] == false && arr[i][j-1] == nextCh){
            isVisited[i][j-1] = true;
            spread(isVisited, arr, word, i, j-1, idx+1);
            isVisited[i][j-1] = false;
        }

        // top
        if(i-1>=0 && isVisited[i-1][j] == false && arr[i-1][j] == nextCh){
            isVisited[i-1][j] = true;
            spread(isVisited, arr, word, i-1, j, idx+1);
            isVisited[i-1][j] = false;
        }

        // right
        if(j+1<m && isVisited[i][j+1] == false && arr[i][j+1] == nextCh){
            isVisited[i][j+1] = true;
            spread(isVisited, arr, word, i, j+1, idx+1);
            isVisited[i][j+1] = false;
        }

        // bottom
        if(i+1<n && isVisited[i+1][j] == false && arr[i+1][j] == nextCh){
            isVisited[i+1][j] = true;
            spread(isVisited, arr, word, i+1, j, idx+1);
            isVisited[i+1][j] = false;
        }
        
        return;
    }

    private void solve(char[][] arr, String word){

        int n = arr.length;
        int m = arr[0].length;

        boolean[][] isVisited = new boolean[n][m];

        char firstCh = word.charAt(0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char ch = arr[i][j];
                
                if(ch == firstCh){
                    isVisited[i][j] = true;
                    spread(isVisited, arr, word, i, j, 1);
                    isVisited[i][j] = false;
                }

            }
        }

    }

    public boolean exist(char[][] board, String word) {

        ans = false;
        solve(board, word);
        return ans;
        
    }
}