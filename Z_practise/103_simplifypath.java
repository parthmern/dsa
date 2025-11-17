class Solution {
    public String simplifyPath(String path) {
        
        Stack<String> st = new Stack<>();
        int i=0;
        while( i<path.length() ){

            int s = i;
            int e = i+1;

            while( e<path.length() && path.charAt(e) != '/' ){
                e++;
            }

            String temp = path.substring(s, e);
            i = e;

            if( temp.equals("/..") && !st.empty() ){
                st.pop();
            }

            if( temp.equals("/.") || temp.equals("/") ){
                continue;
            }

            if (temp.equals("/..")){

            }else{
                st.push(temp);
            }

        }

        if (st.isEmpty()) return "/";

        StringBuilder sb = new StringBuilder();
        for (String s : st) sb.append(s);
        return sb.toString();

    }
}