class MinStack {
    Stack<Long> st;
    long minVal;

    public MinStack() {
        st = new Stack<>();
        minVal = Long.MAX_VALUE;
    }

    public void push(int val) {
        long value = (long) val;

        if (st.isEmpty()) {
            st.push(value);
            minVal = value;
        } 
        else if (value < minVal) {
        
            st.push(2L * value - minVal);
            minVal = value;
        } 
        else {
            st.push(value);
        }
    }

    public void pop() {
        if (st.isEmpty()) return;

        long top = st.pop();
        if (top < minVal) {
            minVal = 2 * minVal - top;
        }
    }

    public int top() {
        long top = st.peek();

        if (top < minVal) {
            return (int) minVal;
        }

        return (int) top;
    }

    public int getMin() {
        return (int) minVal;
    }
}
