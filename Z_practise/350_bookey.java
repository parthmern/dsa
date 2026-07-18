class Solution {

    private int noOfBookey(int[] arr, int currDay, int originalK){

        int totalBookey = 0;

        int k = originalK;

        for(int ele: arr){

            boolean isBloomed = currDay-ele >= 0;

            if(isBloomed){
                k--;
                if(k==0){
                    totalBookey++;
                    k = originalK;
                }
            }else{
                k = originalK;
            }

        }

        return totalBookey;

    }

    private int bs(int[] arr, int s, int e, int m, int k){

        int ans = Integer.MAX_VALUE;

        while(s<=e){
            int mid = (s+e)/2;
            int book = this.noOfBookey(arr, mid, k);

            System.out.println("mid"+ s+ e + mid + " " + book);

            if(book >= m){
                ans = Math.min(ans, mid);
            }
            
            if(book>=m)e=mid-1;
            else s=mid+1;

        }

        return ans;

        
    }

    public int minDays(int[] bloomDay, int m, int k) {

        int s = Integer.MAX_VALUE;
        int e = Integer.MIN_VALUE;

        for(int ele: bloomDay){
            s = Math.min(s, ele);
            e = Math.max(e, ele);
        }
        
        int ans = this.bs(bloomDay,s,e,m,k);
        return ans == Integer.MAX_VALUE ? -1 : ans ;
    }
}