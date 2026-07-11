class Solution {
    public int maxProfit(int[] prices) {

        int ans = 0;
        
        int li = 0;

        for(int i=0; i<prices.length; i++){

            if( prices[li] > prices[i] ){
                li = i;
            }

            int profit = prices[i] - prices[li];

            ans = Math.max(ans, profit);

        }

        return ans;

    }
}