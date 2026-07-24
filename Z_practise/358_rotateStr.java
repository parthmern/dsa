class Solution {
    public boolean rotateString(String s, String goal) {

        if(s.length() != goal.length()) return false;

        String dual = s.concat(s);

        int idx = dual.indexOf(goal);

        if(idx == -1) return false;
        return true;
        
    }
}