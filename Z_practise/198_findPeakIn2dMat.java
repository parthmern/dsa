class Solution {

    public int[] findPeakGrid(int[][] mat) {
        
        int s = 0; // r
        int e = mat[0].length-1; // c

        while( s<=e ){

            int mid = (s+e)/2;
            
            int maxEle = -1;
            int maxR = -1;
            int maxC = -1;
            for(int i=0; i<mat.length; i++){
                if(mat[i][mid] > maxEle){
                    maxEle = mat[i][mid];
                    maxR = i;
                    maxC = mid;
                }
            }

            System.out.println("->" + maxR + " " + maxC);


            // check left and check right
            if( maxC-1>=0 && (maxC-1<mat[0].length) && (mat[maxR][maxC-1] > maxEle) ){
                e=mid-1;
            }else if(  maxC+1>=0 && maxC+1<mat[0].length && mat[maxR][maxC+1] > maxEle ){
                s=mid+1;
            }else{
                return new int[]{maxR, maxC};
            }

        }

        return new int[]{-1, -1};


    }
}