class Solution {

    private int howManyDays(int[] arr, int days, int mid){

        int count = 0;
        int curr = 0;
        for(int ele: arr){
            
            if(curr+ele>mid){
                count++;
                curr=0;
            }

            curr = curr+ele;

        }

        return curr>0 ? count+1: count;

    }

    public int shipWithinDays(int[] weights, int days) {
        
        int mini = Integer.MAX_VALUE;
        int sum = 0;

        int maxi = Integer.MIN_VALUE;

        for(int ele: weights){
            mini = Math.min(mini, ele);
            maxi = Math.max(maxi, ele);
            sum+=ele;
        }

        int s = maxi;
        int e = sum;

        int res = -1;

        while(s<=e){

            int mid = (s+e)/2;
            int ans = howManyDays(weights, days, mid);

            System.out.println("for mid"+ mid + " ans is" + ans);

            if(ans<=days){
                e = mid-1;
                res = mid;
            }else{
                s = mid+1;
            }

        }

        return res;

    }
}