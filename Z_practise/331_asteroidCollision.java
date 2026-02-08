import java.util.*;

class Solution {
    public int[] asteroidCollision(int[] asteroids) {

        Stack<Integer> st = new Stack<>();

        for(int a : asteroids){

            boolean destroyed = false;
            
            // asteroid neg and peek should be +ve so can collide
            while(!st.isEmpty() && a < 0 && st.peek() > 0){

                if(st.peek() < -a){
                    st.pop();    
                    continue;
                }
                else if(st.peek() == -a){
                    st.pop();    // both same remove both
                }

                destroyed = true;
                break;
            }

            if(!destroyed){
                st.push(a);
            }
        }

        int[] res = new int[st.size()];
        for(int i = res.length-1; i >= 0; i--){
            res[i] = st.pop();
        }

        return res;
    }
}
