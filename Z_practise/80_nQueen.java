class Solution {

    private List<List<String>> ans = new ArrayList<>();

    public boolean canVisit( int[][] arr, int i, int j){

        int goStraightBack = j;
        while(goStraightBack >= 0){
            if(arr[i][goStraightBack] == 1){
                return false;
            }
            goStraightBack--;
        }
        
        int goUpJ = j;
        int goUpI = i;

        while( goUpJ >=0 && goUpI >=0 ){
            if(arr[goUpI][goUpJ] == 1){
                return false;
            }
            goUpJ--;
            goUpI--;
        }


        int goDownI = i;
        int goDownJ = j;

        int n = arr.length;
        while( goDownJ >=0 && goDownI < n ){
            if(arr[goDownI][goDownJ] == 1){
                return false;
            }
            goDownJ--;
            goDownI++;
        }
        
        return true;
    }

    public void helper(int[][] arr, int j, int n) {

        if (j >= n) {
            List<String> tempList = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                StringBuilder row = new StringBuilder();
                for (int x = 0; x < n; x++) {
                    row.append(arr[i][x] == 1 ? "Q" : ".");
                }
                tempList.add(row.toString());
            }
            ans.add(tempList);
            return;
        }

        for (int i = 0; i < n; i++) {
            // col wise
            if ( canVisit(arr, i, j)) {
                arr[i][j] = 1;
                helper(arr, j + 1, n);
                arr[i][j] = 0;
            }

        }

    }

    public List<List<String>> solveNQueens(int n) {
        ans.clear();
        int[][] arr = new int[n][n];
        helper(arr, 0, n);
        return ans;
    }

}