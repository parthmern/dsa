#include <iostream>
#include <queue>

using namespace std;

int main(){
    // create max heap
    priority_queue<int> pq;

    // insert
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);

    cout << pq.top() << endl;   // 50

    pq.pop();   // remove top ele which is 50
    cout << pq.top() << endl;   // 40

    cout << pq.size() << endl;  //4

    cout << pq.empty() << endl; // 0 false

}