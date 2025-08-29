#include <iostream>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert at end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Function to print list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to sort list of 0s, 1s, 2s
Node* sortList(Node* head) {
    if (!head || !head->next) return head;

    map<int, int> mp;

    Node* curr = head;

    while(curr!=NULL){
        mp[curr->data]++;
        curr = curr->next;
    }

    for(auto x: mp){
        cout<< x.first << x.second; 
    }

    Node* zerothminusNode = new Node(-1);
    Node* zeroHead = zerothminusNode;
    Node* zeroTail = zerothminusNode;
    while(mp[0]--){
        cout << "run time for 0"<< endl;
        Node* newNode = new Node(0);
        zeroTail->next = newNode;
        zeroTail = newNode;
    }

    Node* onethminusNode = new Node(-1);
    Node* oneHead = onethminusNode;
    Node* oneTail = onethminusNode;
    while(mp[1]--){
        cout << "run time for 1"<< endl;
        Node* newNode = new Node(1);
        oneTail->next = newNode;
        oneTail = newNode;
    }

    Node* twothminusNode = new Node(-1);
    Node* twoHead = twothminusNode;
    Node* twoTail = twothminusNode;
    while(mp[2]--){
        cout << "run time for 2"<< endl;
        Node* newNode = new Node(2);
        twoTail->next = newNode;
        twoTail = newNode;
    }

    if(zeroHead->next!=NULL){
        zeroHead = zeroHead->next;
    }

    if(oneHead->next!=NULL){
        oneHead = oneHead->next;
    }

    zeroTail->next = oneHead;

    if(twoHead->next!=NULL){
        twoHead = twoHead->next;
    }

    oneTail->next = twoHead;

    twoTail->next = NULL;


    return zeroHead;
}

int main() {
    Node* head = nullptr;

    // Example input
    insert(head, 1);
    insert(head, 0);
    insert(head, 2);
    insert(head, 1);
    insert(head, 0);

    cout << "Before sorting: ";
    printList(head);

    head = sortList(head);

    cout << "After sorting: ";
    printList(head);

    return 0;
}
