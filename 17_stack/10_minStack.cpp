// https://leetcode.com/problems/min-stack/

class MinStack {
public:

    vector< pair<int,int> > st;

    MinStack() {
        
        
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int,int> p = make_pair(val,val);
            st.push_back(p);
        }else{
            pair<int,int> p;
            p.first = val;
            p.second = min(val, st.back().second);  // min of currVal and abtak ka minimum means stackTop par ka min
            st.push_back(p);
        } 
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        // stack k top par
        return st.back().first;
    }
    
    int getMin() {
        // stack k top par
        return st.back().second;
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