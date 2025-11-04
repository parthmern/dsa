class Solution {
    public String removeOccurrences(String s, String part) {

        StringBuffer str = new StringBuffer(s);

        while( str.indexOf(part) != -1 ){

            int index = str.indexOf(part);

            str.delete(index, index+part.length());

        }

        return str.toString();
        
    }
}