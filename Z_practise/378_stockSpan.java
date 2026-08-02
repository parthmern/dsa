class StockSpanner {

    int index = 0;

    public Stack<int[]> st;

    public StockSpanner() {
        st= new Stack<>();
    }
    
    public int next(int price) {

        while(!st.empty() && st.peek()[0] <= price ){
            st.pop();
        }
        int[] top = !st.empty() ? st.peek() : new int[]{0,0};
        index++;
        int ans = index - top[1];
        st.push(new int[]{price, index});
        return ans;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */