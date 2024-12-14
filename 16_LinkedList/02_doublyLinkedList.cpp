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

void insertAtTail(Node* &head, Node* &tail, int data){

    if(head == NULL){
        // empty ll

        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;

        return;
    }

    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(head == NULL){
        // empty ll
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position==1){
        insertAtHead(head,tail,data);
        return;
    }

    if(position>getLength(head)){
        insertAtTail(head,tail,data);
        return;
    }

    // insert in middle

    //1) find prev and curr
    Node* prevNode = head;

    // int i = 1;
    // while(i<position-1){
    //     prevNode = prevNode->next;  
    //     i++; 
    // }

    for(int i=0; i<position-2; i++){
        cout << i << "=>" << prevNode-> data << endl;
        prevNode = prevNode->next;
    }

    cout <<"after loop prevNode is" << prevNode-> data << "and prev->next means currentNode is " << prevNode->next->data << endl;

    Node* currNode = prevNode->next;

    // 2)
    Node* newNode = new Node(data);

    //3)
    prevNode->next = newNode;
    newNode->prev = prevNode;
    currNode->prev = newNode;
    newNode->next = currNode;


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

    insertAtTail(head,tail,501);

    insertAtPosition(head,tail,5,401);

    print(head);


    return 0;
}