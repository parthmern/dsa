class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int dificit = 0;
        int bal = 0;
        int start = 0;
        for(int i=0; i<gas.size(); i++ ){
            bal = bal + gas[i] - cost[i];
            if(bal<0){
                start = i+1;
                dificit = dificit+ bal;
                bal= 0;
            }
        }

        if(dificit+ bal>=0) return start;

        return -1;
    }
};