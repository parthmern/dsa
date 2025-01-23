#include <iostream>
using namespace std;

class Deque{

    public:
        int* arr;
        int size;
        int front;
        int rear;

        Deque(int size){
            this->size = size;
            arr = new int[size];
            rear = -1;
            front = -1;
        }

        void pushRear(int data){
            // queue is full
            if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ){
                cout << "queue is full cannot insert" << endl;
            }

            // single ele case -> first ele insert
            else if( front==-1 && rear==-1 ){
                front = 0;
                rear = 0;
                arr[rear] = data;
            }

            // circular nature
            else if( rear == size-1 && front != 0 ){
                rear = 0;
                arr[rear] = data;
            }

            // normal queue
            else{
                rear++;
                arr[rear] = data;
            }
        }

        void pushFront(int data){
            // queue is full
            if( (front == 0 && rear == size-1) || (rear == (front-1)%(size-1) ) ){
                cout << "queue is full cannot insert" << endl;
            }

            // single ele case -> first ele insert
            else if( front==-1 && rear==-1 ){
                front = 0;
                rear = 0;
                arr[front] = data;
            }

            // circular nature
            else if( rear != size-1 && front == 0 ){
                front = size-1;
                arr[front] = data;
            }

            // normal queue
            else{
                front--;
                arr[front] = data;
            }
        }


        void popFront(){
            // empty check
            if(front == -1){
                cout << "q is empty cannot pop" << endl;
            }

            // single ele
            else if(front==rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }

            // circular nature
            else if(front == size-1){
                front = 0;
            }

            // normal flow
            else{
                front++;
            }
        }

        void popRear(){
             // empty check
            if(front == -1){
                cout << "q is empty cannot pop" << endl;
            }

            // single ele
            else if(front==rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }

            // circular nature
            else if(rear == 0){
                rear = size - 1;
            }

            // normal flow
            else{
                rear--;
            }
        }



};

int main(){




    return 0;
}