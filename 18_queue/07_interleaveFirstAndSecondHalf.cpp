#include <iostream>
#include <queue>

using namespace std;

void interLeaveQueue(queue<int> & q){

    // step 1) seperate two halfs
    int n = q.size();

    if(n<=0 || q.empty()) return;

    int k = n/2;
    int count = 0;

    queue<int> q2; 

    while(!q.empty()){
        int data = q.front();
        q.pop();
        q2.push(data);
        count++;

        if(count == k){
            break;
        }
    }

    // step 2) interliving
    while(!q.empty() && !q2.empty()){
        int first = q2.front();
        q2.pop();
        q.push(first);

        int second = q.front();
        q.pop();
        q.push(second);
    }

    // odd case k andar ek extra ele rahega
    while(n&1){ // n is odd then
        int temp = q.front();
        q.pop();
        q.push(temp);
    }


}

int main(){

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    interLeaveQueue(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }


    return 0;
}