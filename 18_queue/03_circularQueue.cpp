#include <iostream>
using namespace std;

class CricularQueue{

    public:
        int size;
        int* arr;
        int front;
        int rear;

        CricularQueue(int size){
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void push(int data){

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

        void pop(){

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





};

int main(){

    
    
    return 0;
}