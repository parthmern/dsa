class Solution {
  public:
  
    vector<string> ans;
    
    bool canWeVisit(vector<vector<int>>& maze, vector<vector<int>>& isVisited, int i, int j){
        
        int row = maze.size();
        int col = maze[0].size();
        
        if( (( i>=0 && i<row )) && ( (j<col)&&(j>=0)) && (maze[i][j] == 1 )&& (isVisited[i][j]!=1) ){
            return true;
        }else{
           // cout << "false " << i << j <<endl;
            return false;
        }
        
    }
    
    void solve(vector<vector<int>>& maze, vector<vector<int>>& isVisited, int i, int j, string currentAns){
        int row = maze.size();
        int col = maze[0].size();
        
        //cout << "i" << i <<j << endl;
         
        if( i == row-1 && j == col-1 ){
            cout << "ans" << currentAns << endl;
            ans.push_back(currentAns);
            return;
        }
        
        // down
        if( canWeVisit(maze, isVisited, i+1, j) ){
            isVisited[i+1][j] = 1;
            solve(maze,isVisited,i+1,j,currentAns+'D' );
            isVisited[i+1][j] = 0;
        }
        // left
         if( canWeVisit(maze, isVisited, i, j-1) ){
            isVisited[i][j-1] = 1;
            solve(maze,isVisited,i,j-1, currentAns + 'L');
            isVisited[i][j-1] = 0;
        }
        // up
         if( canWeVisit(maze, isVisited, i-1, j) ){
            isVisited[i-1][j] = 1;
            solve(maze,isVisited,i-1,j, currentAns + 'U');
            isVisited[i-1][j] = 0;
        }
        // right
         if( canWeVisit(maze, isVisited, i, j+1) ){
            isVisited[i][j+1] = 1;
            solve(maze,isVisited,i,j+1, currentAns + 'R');
            isVisited[i][j+1] = 0;
        }
        
    
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        
       int n = maze.size();
       vector<vector<int>> isVisited(n, vector<int>(n, 0));
       isVisited[0][0] = 1;
       string o = "";
       
       solve(maze, isVisited, 0, 0, o);
       return ans;
        
        
    }
};