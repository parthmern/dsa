#include <iostream>
#include <queue>

using namespace std;

int main(){
    // create min heap
   priority_queue<int,vector<int>,greater<int>>pq;

   // insert
   pq.push(100);
   pq.push(90);
   pq.push(70);

   cout << pq.top() << endl;    // 70

   pq.pop();
   cout << pq.top() << endl;    // 90

   cout << pq.size() << endl;   // 2
   

}