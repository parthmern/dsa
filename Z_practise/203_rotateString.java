class Solution {
    public boolean rotateString(String s, String goal) {
        if(s.length()!=goal.length()) return false;
        int index = goal.indexOf(s.charAt(0));
        if(index==-1) return false;
        
        // for(int i=0; i<s.length(); i++){
        //     int original = s.charAt(i);
        //     int dup = goal.charAt(index);
        // }

        StringBuilder str = new StringBuilder("");
        str.append(goal.substring(index));
        str.append(goal.substring(0,index));

        System.out.println("oa"+ goal);

        if(s.equals(str.toString())==false){
            for(int indexx=0; indexx<s.length(); indexx++){
                StringBuilder strr = new StringBuilder("");
                strr.append(goal.substring(indexx));
                strr.append(goal.substring(0,indexx));
                if(s.equals(strr.toString())) return true;
            }
          
        }else{
            return true;
        }

        return false;

    }
}