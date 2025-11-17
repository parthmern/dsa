class StockSpanner {

    public Stack<int[]> st;

    public StockSpanner() {
        st= new Stack<>();
    }
    
    public int next(int price) {

        int count = 1;
        while(!st.empty() && st.peek()[0] <= price ){
            int[] arr = st.pop();
            count = count + arr[1];
        }

        st.push(new int[]{price, count});
        return count;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */