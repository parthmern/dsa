class Solution {
    public boolean isValid(String s) {

        int fi = s.indexOf("abc");
        while( fi != -1 ){
            s = s.substring(0, fi) + s.substring(fi + 3);
            fi=s.indexOf("abc");
        }
        
        return s.equals("");  
    }
}