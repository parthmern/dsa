#include <iostream>
using namespace std;

class Queue {

    public:
        int * arr;
        int size;
        int front;
        int rear;

        Queue(int size){
            this->size = size;
            arr = new int[size];
            front = 0;
            rear = 0;
        }

        void push(int data){

            if(rear == size){
                cout << "queue is full" << endl;
            }else{
                arr[rear] = data;
                rear++;
            }

        }

        void pop(){
            if(front == rear){
                cout << "queue is empty" << endl;
            }else{
                arr[front] = -1;
                front++;

                if(front==rear){
                    // restart from 0th
                    front = 0;
                    rear = 0; 
                }
            }
        }

        int getFront(){

            if(front==rear){
                cout << "queue is empty" << endl;
            }
            else{
                return arr[front];
            } 

        }

        bool isEmpty(){
            if(front==rear){
                return true;
            }else{
                return false;
            }
        }

        int getSize(){
            if(front==rear){
                cout << "queue is empty" << endl;
                return 0;
            }else{
                return (rear-front);
            }
        }

};

int main(){

    Queue q(10);

    
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    cout << "size of queue => " << q.getSize() << endl;
    q.pop();
    cout << "size of queue => " << q.getSize() << endl;

    cout << "front ele is=> "<< q.getFront() << endl; 

    if(q.isEmpty()){
        cout << "q  ueue is empty" << endl;
    }
    else{
        cout << "queue is not empty" << endl;
    }
    
    return 0;
}