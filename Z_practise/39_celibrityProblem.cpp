class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        
        int top = 0;
        int down = mat.size()-1;
        
        while(top<down){
            if(mat[top][down] == 1){ // if know then it cannot be Celebrity
                top++;      
            }else if(mat[down][top] == 1){
                down--;
            }else{
                top++;
                down--;
            }
        }
        
        if(top>down) return -1; //not standing at single person
        
        for(int i=0; i<mat.size(); i++){
            if((mat[top][i] == 0 ) && mat[i][top] ==1){
                
            }else{
                return -1;
            }
        }
        
        return top;
        
    }
};