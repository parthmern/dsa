#include <iostream>
#include <stack>
using namespace std;

int main(){

    // creation 
    stack<int> s;

    // push
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // pop
    s.pop();

    // ele on top
    cout << s.top() << endl;

    // size
    cout << s.size() << endl;

    // is empty
    cout << s.empty() << endl;

    // print
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    

    return 0;
}