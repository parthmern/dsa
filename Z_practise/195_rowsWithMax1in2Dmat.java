class Solution {
    
    int lowerBoundIndex(int[] arr, int target){

        int s = 0;
        int e = arr.length-1;

        int res = -1;
        // 1 1 2 2 3 3 4 4 (t=2, mid=3) 3>2 then left search
        while(s<=e){
            int mid = (s+e)/2;
            if(arr[mid] == target){
                res = mid;
                e=mid-1;
            }else if( arr[mid] > target ){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }

        System.out.println("res " +res);
        return res;

    }

    public int[] rowAndMaximumOnes(int[][] mat) {

        int[] ans = new int[]{0, 0};

        int i = 0;
        for(int[] arr : mat){
            Arrays.sort(arr);
            // 0 1 1 => len 3 | lbdi 1 = 3-1= 2
            int lbdi = lowerBoundIndex(arr, 1);
            int len = arr.length - lbdi;
            System.out.println("len"+len);
            if(lbdi!=-1 && ans[1]<len){
                ans[0] = i;
                ans[1] = len;
            }
            i++;
        }

        return ans;

    }
}