class StockSpanner {
public:

    // int- index | int - price
    stack<pair<int, int>> st;

    int index = 0;

    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        
        while(!st.empty() && st.top().second<=price){
            st.pop();
        }

        index = index + 1;

        int topmostIndex = st.empty() ? 0 : st.top().first;
        int ans = index - topmostIndex;

        pair<int,int> newPair;
        newPair.first = index;
        newPair.second = price;
        st.push(newPair);

        return ans;
    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */