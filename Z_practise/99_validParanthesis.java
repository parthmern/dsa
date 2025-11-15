class Solution {
    public boolean isValid(String s) {
        
        Stack<Character> st = new Stack<>();

        List<Character> list = new ArrayList<>(Arrays.asList('(', '{', '['));   // mutable can add remove
        // Arrays.asList(array)   // can pass int[] array

        // List<Character> list = Arrays.asList('(', '{', '[');                
        // non mutable cannot add remove (can set only list.set(1, 'X');)

        // List.of('(', '{', '[');  // non mutable + set not work + null cannot add

        for(int i=0; i<s.length(); i++){
            
            char ele = s.charAt(i);

            if(list.contains(ele)){
                st.push(ele);
            }else{
                
                char top = st.pop();
                if( ele == ')' ){
                    if(top != '(') return false;
                }

                if( ele == ']' ){
                    if(top != '[') return false;
                }

                if(ele == '}'){
                    if(top != '{') return false;
                }
            }
        }

        return true;

    }
}