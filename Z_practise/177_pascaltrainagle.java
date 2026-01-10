class Solution {
    public List<List<Integer>> generate(int numRows) {

        List<List<Integer>> ans = new ArrayList<>();
        
        // c = c * (i-j) / j 

        
        int n = numRows;
        for(int i=1; i<=n; i++){
            int c = 1;
            List<Integer> temp = new ArrayList<>();
            for(int j=1; j<=i; j++){
                temp.add(c);
                c = c * (i-j)/j;
            }

            ans.add(temp);

        }

        return ans;

    }
}