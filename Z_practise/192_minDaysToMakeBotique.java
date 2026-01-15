class Solution {

    private int totalMadeBotique(int[] arr, int k, int mid){
        //System.out.println(" mid " + mid);

        // k = no of adj flowers
        // m = no of botique

        int adjFlowers = k;
        int count = 0;

        for(int i=0; i<arr.length; i++){

            int ele = arr[i];

            //System.out.println("adjFlowers" + adjFlowers);

            if( ele - mid <= 0 ){
                // mean that flower grownup already
                adjFlowers--;
                if(adjFlowers == 0){
                    //System.out.println("got at "+ i + " ele "+ ele);
                    count++;
                    adjFlowers=k;
                }
            }else{
                adjFlowers=k;
            }

        }

        //System.out.println("for mid "+mid + " -------------- totalMadeBotique "+ count);

        return count;

        
    }

    public int minDays(int[] bloomDay, int m, int k) {
        
        // min days required means min in arr
        // max days are max from arr

        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;

        for(int ele : bloomDay){
            mini = Math.min(mini, ele);
            maxi = Math.max(maxi, ele);
        }

        int s = mini;
        int e = maxi;

        int ans = -1;

        while(s<=e){
            int mid = (s+e)/2; 
            int totalMade = totalMadeBotique(bloomDay, k, mid);

            if(totalMade >= m){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
            
        }

        return ans;
        
    }
}