class Solution {
    public String largestOddNumber(String num) {
        int rightMostOddIndex = -1;
        for(int i=0; i<num.length(); i++){
            String ele = num.charAt(i) + "";
            int div = Integer.valueOf(ele) % 2;
            if( div != 0 ) rightMostOddIndex = i;
        }

        System.out.println("ri" + rightMostOddIndex);

        if(rightMostOddIndex == -1) return "";
        else return num.substring(0, rightMostOddIndex+1);

    }
}