#include <iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* next;

        Node(){
            this->data = 0;
            this->next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            int value = this -> data;
            //memory free
            if(this->next != NULL) {
                delete next;
                this->next = NULL;
            }
            cout << " memory is free for node with data " << value << endl;
        }

};

void print(Node* &head){

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }

    Node*temp = head;
    while( temp != NULL ){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

// i want to insert a node right at the head of linked list 
// (here head passed as referenace so can change in orignal)
void insertAtHead(Node* &head, Node* &tail,int data){

    if(head == NULL){
        //empty ll 

        Node* newNode = new Node(data);

        // means newNode is going to be first node 
        head = newNode;
        tail = newNode;
        
    }
    else{
        //1)create a newNode
        Node* newNode = new Node(data);

        //2) attach newNode->next to head
        newNode->next = head;

        //3) update head as newNode
        head = newNode; 
    }
}


// i want to insert a new node right at the end of linkedlist
void insertAtTail(Node* &head, Node* &tail, int data){

    if(head == NULL){
        //empty ll 

        Node* newNode = new Node(data);

        // means newNode is going to be first node 
        head = newNode;
        tail = newNode;

        return; 
        
    }
    
        //1)create a newNode
        Node* newNode = new Node(data);

        //2) attach tail->next to newNode
        tail->next = newNode;

        //3) update tail as newNode
        tail = newNode;
    
}

int findLength(Node* &head){
    Node* temp = head;

    int len = 0;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }

    return len;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int data){

    if(head == NULL){
        //empty ll 

        Node* newNode = new Node(data);

        // means newNode is going to be first node 
        head = newNode;
        tail = newNode;
        
    }
    else if(position==0){
        insertAtHead(head,tail,data);
    }
    else if(position>=findLength(head)){
        insertAtTail(head,tail,data);
    }
    else{
        //1) find position: prev & curr
        int i=1;
        Node* prev = head;

        while(i<position){
            prev = prev->next;
            i++;
        }

        Node* curr = prev->next;

        //2) create newNode
        Node* newNode = new Node(data);

        //3) newNode-> next = current
        newNode-> next = curr;

        //4) prev->next = current
        prev->next = newNode;

    }

    
}

void deleteNode(Node* &head, Node* &tail, int position){
    if(head == NULL){
        //empty ll 
        cout << "cannot delte Linkedlist is empty" << endl;
        return;
    }

    int len = findLength(head);

    if (position < 1 || position > len) {
        // Invalid position
        cout << "Invalid position" << endl;
        return;
    }


    // delete at head (first node)
    if(position==1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // delete at tail (last node)
    if(position == findLength(head)){
        //1)find previous
        int i=1;
        Node* prev = head;

        while(i<position-1){
            prev = prev->next;
            i++;
        }


        //2) prev->next ko null
        prev->next = NULL;

        //3) got temp as tail
        Node* temp = tail;

        //4) arange temp as tail
        tail = prev;

        //5) 
        delete temp;

        return;
    }

    // deleting middle node
    //1) find position: prev & curr
        int i=1;
        Node* prev = head;

        while(i<position-1){
            prev = prev->next;
            i++;
        }

        Node* curr = prev->next;

        //2)
        prev->next = curr->next;

        //3) 
        curr->next = NULL;

        //4)
        delete curr;

}

Node* reverse(Node* &prev, Node* &curr){

    // base case 
    if(curr == NULL){
        return prev; // new head
    }

    // rr
    Node* forward = curr->next;
    curr->next = prev;

    reverse(curr,forward);

}


Node* reverseUsingLoop(Node* &head){

    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
    
        prev = curr;
        curr = temp;
    }

    return prev;


}

Node* reverseUsingRecursion(Node* &prev, Node* &curr){

    // base case 
    if(curr == NULL){
        return prev; // new head
    }

    // rr
    Node* temp = curr->next;
    curr->next = prev;

    prev = curr;
    curr = temp;

    reverseUsingRecursion(prev,temp);

}


int main(){

    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    // print(first);

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head,tail,20);
    insertAtHead(head,tail,50);
    insertAtHead(head,tail,60);
    insertAtHead(head,tail,90);

    insertAtTail(head,tail,77);

    insertAtPosition(head,tail,2,101);
    insertAtPosition(head,tail,0,201);  // at head
    insertAtPosition(head,tail,6,505);  // at tail

    print(head);

    cout <<"after deleteing.."<< endl;
    deleteNode(head,tail,1);
    deleteNode(head,tail,7);
    deleteNode(head,tail,2);

    print(head);


    cout<< "after reversing .." << endl;

    Node* prev = NULL;
    Node* curr = head;
    head = reverse(prev, head);

    print(head);

    head = reverseUsingLoop(head);
    cout<< "after reversing .." << endl;
    print(head);

    prev = NULL;
    head = reverseUsingRecursion(prev, head);
    cout<< "after reversing .." << endl;
    print(head);

    
     

    return 0;
}