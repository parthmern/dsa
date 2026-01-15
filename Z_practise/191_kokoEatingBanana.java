class Solution {
    
    private long countTotalHrs(int[] arr, int perHr){

        System.out.println("perhr"+ perHr);

        long ans = 0;

        for(int ele: arr){

        long div = (long) (ele / perHr);
        long mod = (long) (ele % perHr);


            if(mod==0){
                ans = ans+div;
            }else{
                ans = ans+div+1;
            }


           // System.out.println("ans"+ans + "for ele "+ ele);

            // ans = ans+div+1;

        }

        return ans;

    }

    private int totalBananaPerHr(int[] arr, int h, int s, int e){

        int res = -1;

        int  mid = (s+e)/2;

        while(s<=e){

            long  ans = countTotalHrs(arr, mid);
            System.out.println("ams"+ ans);

            if( ans == (long)h ){
                res = mid;
                e = mid-1;
            }else if( ans > (long)h ){
               
                s = mid+1;
            }else{
                res = mid;

                e = mid-1;
            }
            mid = (s+e)/2;
        }
        
            return res;

    }

    public int minEatingSpeed(int[] piles, int h) {

        // if(piles.length == 1){
        //     piles[0];
        // }

        int maxEle = 0;
        int minEle = Integer.MAX_VALUE;

        for(int ele: piles){
            minEle = Math.min(minEle, ele);
            maxEle = Math.max(maxEle, ele);
        }

        return totalBananaPerHr(piles, h, 1, maxEle);

    }
}