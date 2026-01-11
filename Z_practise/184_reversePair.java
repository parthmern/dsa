class Solution {

    int ans;

    private void mergeTwoSortedArr(int[] arr, int s, int e){

        int mid = (s+e)/2;

        int[] temp = new int[e-s+1];
        int index = 0;
        
        int i = s;
        int j = mid+1;

        // reverse pair
        int ri = s;
        int rj = mid+1;
        int c =0;

        while( ri <=mid ){

            while (rj <= e && (long) arr[ri] > 2L * arr[rj]) {
                rj++;
            }
            ans += (rj - (mid + 1));

            ri++;
            //rj = mid+1;
        }

        while(i<=mid && j<=e){
            if(arr[i]<arr[j]){
                temp[index] = arr[i];
                i++;
                index++;
                // count inversion c = c + (mid-i+1)
            }else{
                temp[index] = arr[j];
                j++;
                index++;
            }
        }

        while(i<=mid){
            temp[index] = arr[i];
            i++;
            index++;
        }

        while(j<=e){
            temp[index] = arr[j];
            j++;
            index++;
        }

        int idx = s;
        for(int k=0; k<temp.length; k++){
            arr[idx] = temp[k];
            idx++;
        }

    }

    private void ms(int[] nums, int s, int e){

        if(s>=e) return;

        int mid = (s+e)/2;

        ms(nums, s, mid);
        ms(nums, mid+1, e);
        mergeTwoSortedArr(nums, s, e);

    }

    public int reversePairs(int[] nums) {
        
        // merge sort algo
        ms(nums, 0, nums.length-1);
        System.out.println(Arrays.toString(nums));

        return ans;


    }
}