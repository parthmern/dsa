#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int getLength(Node* &head){
    Node* temp = head;
    int len = 0;

    while(temp!=NULL){
        temp = temp->next;
        len++;
    }

    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){

    if(head == NULL){
        // empty ll

        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;

        return;

    }

    //1) create newNode
    Node* newNode = new Node(data);

    //2) newNode->next connect to head
    newNode->next = head;

    //3) head->prev ko connect to newNode
    head->prev = newNode;

    //4) update head
    head = newNode;

}

int main(){

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    Node* head = first;
    Node* tail = third;

    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;

    insertAtHead(head,tail,101);

    print(head);


    return 0;
}