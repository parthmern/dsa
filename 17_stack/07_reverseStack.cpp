#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int target){
    //bc
    if(st.empty()){
        st.push(target);
        return;
    }

    // rr
    int topEle = st.top();
    st.pop();
    insertAtBottom(st, target);

    // bkt
    st.push(topEle);
}

void reverseStack(stack<int> & st){
    // bc
    if(st.empty()){
        return;
    }

    int target = st.top();
    st.pop();

    // stack reverese
    reverseStack(st);

    // insert target at bottom
    insertAtBottom(st,target);

}

int main(){

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    reverseStack(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }


}