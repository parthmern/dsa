class Solution {
  public:
  
    bool isPossibleToAllocateCows(vector<int> &stalls, int totalCows, int minPossibleDist){
        int cows = 1;
        int lastPos = stalls[0];
        
        for( int i=0; i<stalls.size(); i++ ){
            if( stalls[i] - lastPos >= minPossibleDist ){
                cows++;
                lastPos = stalls[i];
            }
        }
        
        if( cows >= totalCows ) return true;
        else return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        
        int maxPosssibleDifference = *std::max_element(stalls.begin(), stalls.end());
        std::sort(stalls.begin(), stalls.end());
                    
        int s = 0;
        int e = maxPosssibleDifference;
        int mid = (s+e)/2;
        
        int ans;


        
        while(s<=e){
            if( isPossibleToAllocateCows(stalls, k, mid) ){
                // go right
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
            mid = (s+e)/2;
        }
        
        return ans;
        
        
          
            
        
        
    }
};