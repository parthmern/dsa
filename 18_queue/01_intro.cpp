#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue<int> q ;

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    cout << "size of queue =>" << q.size() << endl;
    q.pop();
    cout << "size of queue =>" << q.size() << endl;

    if(q.empty()){
        cout << "q is empty" << endl;
    }else{
        cout << "q is not empty" << endl;
    }

    cout << "front ele is=> " << q.front() << endl;

    return 0;
}