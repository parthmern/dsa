#include <iostream>
#include <queue>
#include <stack>
using namespace std;


void reverseQueue(queue<int> &q){
    stack<int> st;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        st.push(temp);
    }

    while(!st.empty()){
        int ele = st.top();
        st.pop();
        q.push(ele);
    }

}


int main(){

    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);
    // 3-6-9-2-8

    reverseQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    


}