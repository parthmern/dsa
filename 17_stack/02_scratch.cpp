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
            if(size-top>1){
                // space available
                top++;
                arr[top] = data;
            }else{
                cout << "stack overflow" << endl;
            }
        }

        void pop(){

            if(top==-1){
                cout << "stack underflow/empty" << endl;
            }else{
                top--;
            }

        }

        int getTop(){
            if(top==-1){
                cout << "stack underflow/empty" << endl;
            }else{
                return arr[top];
            }
        }

        int getSize(){
            if(top==-1){
                cout << "stack underflow/empty" << endl;
            }else{
                int totalEle = top+1;
                return totalEle;
            }
        }

        bool empty(){
            if(top==-1){
                return true;
            }else{
                return false;
            }
        }
};

int main(){

    Stack s(10);

    // push
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // pop
    s.pop();

    // ele on top
    cout << s.getTop() << endl;

    // size
    cout << s.getSize() << endl;

    // is empty
    cout << s.empty() << endl;

    // print
    while (!s.empty()){
        cout << s.getTop() << " ";
        s.pop();
    }


}