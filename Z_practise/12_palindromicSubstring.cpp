class Solution {
public:

    int expand(string s, int i, int j){
        int c = 0;

        while( i<=j ){

            if( i<0 || j >= s.length() ){
                break;
            }
            else if( s[i] != s[j] ){
                break;
            }else{
                c ++;
                i--;
                j++;
            }
        }

        cout << i << j << " " << c << endl;
        return c;

    }

    int countSubstrings(string s) {

        int count = 0;

        for(int i=0; i<s.length(); i++){
            int oddKa = expand( s, i, i );
            int evenKa = expand( s, i, i+1);
            count = count + oddKa + evenKa;
        }

        return count;
       
    }
};