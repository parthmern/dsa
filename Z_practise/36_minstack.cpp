class MinStack {
public:

    vector<pair<int, int>> st;

    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int, int> temp;
            temp.first = val;
            temp.second = val;
            st.push_back(temp);
        }else{
            pair<int, int> temp;
            pair<int, int> top = st.back();
            int currentMinVal = top.second;
            if(val<currentMinVal){
                temp.second = val;
            }else{
                temp.second = currentMinVal;
            }
            temp.first = val;
            st.push_back(temp);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        pair<int, int> top = st.back();
        return top.first;
    }
    
    int getMin() {
        pair<int, int> top = st.back();
        return top.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */