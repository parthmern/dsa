class Solution {

    private int total = 0;

    private void expand(String s, int i, int j){

        while( i>=0 && j<s.length() ){
            if( s.charAt(i) == s.charAt(j) ){
                total++;
                i--;
                j++;
            }else{
                break;
            }
        }

    }


    public int countSubstrings(String s) {
        
        // odd
        for(int i=0; i<s.length(); i++){
            expand(s, i, i);
        }

        //even
        for(int i=0; i<s.length()-1; i++){
            expand(s, i, i+1);
        }

        return total;

        
    }
}