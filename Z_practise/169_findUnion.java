class Solution {
    public static ArrayList<Integer> findUnion(int a[], int b[]) {
        // code here
        
        ArrayList<Integer> ans = new ArrayList<>();
        
        int i=0;
        int j=0;
        
        int lastAns = -1;
        while( i<a.length && j<b.length ){
            
            if(a[i] == b[j]){
                if(lastAns != a[i]){
                    ans.add(a[i]);
                    lastAns = a[i];
                }
                i++;
            }
            else if( a[i] < b[j] ){
                if(lastAns != a[i]){
                    ans.add(a[i]);
                    lastAns = a[i];
                }
                i++;
            }else{
                if(lastAns != b[j]){
                    ans.add(b[j]);
                    lastAns = b[j];
                }
                j++;
            }
            
        }
        
        while(i<a.length){
            if(lastAns != a[i]){
                    ans.add(a[i]);
                    lastAns = a[i];
                }
                i++;
        }
        
        while(j<b.length){
             if(lastAns != b[j]){
                    ans.add(b[j]);
                    lastAns = b[j];
                }
                j++;
        }
        return ans;
    }
}
