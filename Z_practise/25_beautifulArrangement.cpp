class Solution {
public:

    int ans = 0;

    void counterHelper(int n, int currentNum,vector<int>& temp) {

        if( currentNum >= n+1 ){
            ans++;
            return;
        }
        
        for(int i=1; i<=n; i++){
            if( (temp[i-1] == 0) && ((currentNum % i == 0 ) || ( i%currentNum ==0 )) ){
                temp[i-1] = currentNum;
                counterHelper(n , currentNum+1, temp);
                temp[i-1] = 0;
            }
        }
        return;
    }

    int countArrangement(int n) {
        vector<int> temp(n, 0);
        counterHelper(n, 1, temp);
        return ans;
    }
};