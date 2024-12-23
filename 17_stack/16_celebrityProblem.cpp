// https://www.geeksforgeeks.org/the-celebrity-problem/



class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        
        int n = mat[0].size();
        stack<int> st;
        
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        while( st.size() != 1 ){
            int personA = st.top(); st.pop();
            int personB = st.top(); st.pop();
            
            if( mat[personA][personB] == 1 ){
                st.push(personB);
            }else{
                st.push(personA);
            }
        }
        
        int mightBeCelebrity = st.top(); st.pop();
        
        for(int i=0; i<n; i++){
            if( mat[mightBeCelebrity][i] != 0 ) return -1;
        }
        
        for(int i=0; i<n; i++){
            if( mat[i][mightBeCelebrity] == 0 && i!=mightBeCelebrity ) return -1;
        }
        
        return mightBeCelebrity;
        
    }
};
