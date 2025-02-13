// https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        
        stack<string> st;
        for(auto ch: s){
            if( ch == ']' ){
                string stringToRepeat = "";
                while( !st.empty() &&  !isdigit(st.top()[0]) ){
                    string top = st.top();
                    stringToRepeat = stringToRepeat + ( top=="[" ? "" : top);
                    st.pop();
                }

                string numericTimes = "";
                while( !st.empty() &&  isdigit(st.top()[0]) ){
                    string top = st.top();
                    numericTimes = numericTimes + top;
                    st.pop();
                }// we got "321" types of digits that we need to convert to "123"
                reverse(numericTimes.begin(), numericTimes.end());

                int n = stoi(numericTimes); // string to int

                // final decoding
                string currentDecode ="";
                while(n--){
                    currentDecode = currentDecode + stringToRepeat ;
                }
                st.push(currentDecode);


            }else{
                string temp(1,ch);  // converting ch to string
                st.push(temp);
            }
        }

        string ans = "";
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};