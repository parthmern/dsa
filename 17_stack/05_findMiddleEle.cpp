#include <iostream>
#include <stack>
using namespace std;

void findMiddleEle(stack<int> &s, int totalSize){
    if(totalSize/2 + 1 == s.size()){
        cout << "middle ele is => "<< s.top() <<endl;
    }
    int temp = s.top();
    s.pop();

    findMiddleEle(s,totalSize);

    s.push(temp);
}

int main(){

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    
    int totalSize = st.size();
    findMiddleEle(st, totalSize);


}