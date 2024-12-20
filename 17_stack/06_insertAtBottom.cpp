#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st, int target){
    //bc
    if(st.empty()){
        st.push(target);
        return;
    }

    // rr
    int topEle = st.top();
    st.pop();
    solve(st, target);

    // bkt
    st.push(topEle);
}

void insertAtBottom(stack<int> &st){
    if(st.empty()){
        cout << "stack is empty cannot insert at bottom" << endl;
        return;
    }

    int target = st.top();
    st.pop();
    solve(st, target);
}


int main(){

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    insertAtBottom(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }


}