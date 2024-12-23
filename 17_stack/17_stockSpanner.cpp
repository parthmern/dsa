// https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:

    stack< pair<int,int> > st;
    int index = -1;
    
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {

        index = index+1;
        while( !st.empty() ){
            if( st.top().first <= price ){
                st.pop();
            }else{
                break;
            }
        }

        int prevGreaterIndex = st.empty() ? -1: st.top().second;
        pair<int,int> p;
        p.first = price;
        p.second = index;
        st.push(p);

        int ans = index - prevGreaterIndex;
        return ans;   
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */