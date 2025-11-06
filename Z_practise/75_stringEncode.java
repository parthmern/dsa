class Solution {
    public static String encode(String s) {
        // code here
        
        String ans= "";
        
        int count = 1;
        
        for(int i=0; i<s.length()-1; i++){
            
            if( s.charAt(i) != s.charAt(i+1) ){
                ans = ans + ( s.charAt(i) + "" ) + String.valueOf(count);
                count = 1;
                //System.out.println(" i is" + i + " " + ans);
            }else{
                count++;
            }
            
        }
        
        ans = ans + ( s.charAt(s.length()-1) + "" ) + String.valueOf(count);
        
        return ans;
        
    }
}