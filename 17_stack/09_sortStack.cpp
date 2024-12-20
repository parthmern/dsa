#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int target){
    // bc
    if( st.empty() || (st.top() >= target) ){
        // stack empty hoga 
        // agar empty hai to st.top() find nhi hoga and wo protection rahega
        st.push(target);
        return;
    }

    // rr
    int top = st.top();
    st.pop();
    insertSorted(st, target);

    //bk
    st.push(top);
}

void sortStack(stack<int> &st){

    // bc
    if(st.empty()){
        return;
    }

    // rr
    int topEle = st.top();
    st.pop();
    sortStack(st);

    // bk
    insertSorted(st,topEle);

}

int main(){

    stack<int> st;

    st.push(7);
    st.push(11);
    st.push(3);
    st.push(5);
    st.push(9);

    sortStack(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

}