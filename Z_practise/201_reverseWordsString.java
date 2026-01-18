class Solution {
    public String reverseWords(String s) {
        String[] str = s.trim().split(" ");
        System.out.println("-"+ Arrays.toString(str));

        StringBuffer ans = new StringBuffer("");

        for(int i=str.length-1; i>=0; i--){
            System.out.println(i + str[i]+"|");
            if(!str[i].equals("")) ans.append( str[i] + " " );
        }

        //ans.trim();
        //ans.split(" ");
        
        return ans.toString().trim();
        
    }
}