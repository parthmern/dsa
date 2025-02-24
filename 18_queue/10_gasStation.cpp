// https://leetcode.com/problems/gas-station/

class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int deficit = 0; // kitna gas kam pad raha he
            int balance = 0; // kitna gas bacha hua he
            int start = 0; // starting index
    
            for(int i=0; i<gas.size(); i++){
                balance = balance + gas[i] - cost[i];   // updated balance
                if(balance<0){
                    deficit = deficit+balance;
                    start = i+1;
                    balance = 0;
                }
            }
    
            if(deficit+balance>=0){
                return start;
            }else{
                return -1;
            }
    
        }
    };