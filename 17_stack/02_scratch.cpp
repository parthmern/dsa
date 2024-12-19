#include <iostream>
using namespace std;

class Stack{

    public:
        int *arr;
        int top;
        int size;

        Stack(int size){
            this->arr = new int[size];
            this->size = size;
            top = -1; // no ele inside
        }

        void push(int data){
            top++;
            arr[top] = data;
        }

        void pop(){

        }

        int getTop(){

        }

        int getSize(){

        }

        bool empty(){

        }
};

int main(){

}