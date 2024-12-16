#include <iostream>
#include <vector>
using namespace std;

// Definition for the Node class
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Helper function to insert a node at the tail of a sublist
void insertAtTail(Node*& tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

// Function to sort the linked list with values 0, 1, and 2
Node* sortList(Node* head) {

    // dummy nodes
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    // Create separate lists for 0s, 1s, and 2s
    while (curr != nullptr) {

        int value = curr->data;

        if (value == 0) {
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            
            zeroTail->next = temp;
            zeroTail = temp;

        } else if (value == 1) {
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            
            oneTail->next = temp;
            oneTail = temp;
        } else if (value == 2) {
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;
            
            twoTail->next = temp;
            twoTail = temp;
        }

        curr = curr->next;
    }

    // modify one wali list
    Node* temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    // modify two wali list
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // join list
    if(oneHead!=NULL){
        // one wali list non empty
        zeroTail->next = oneHead;
        if(twoHead!=NULL){
            oneTail->next = twoHead;
        }
    }
    else{
        // one wali list empty
        if(twoHead != NULL){
            zeroTail->next = twoHead; 
        }
    }

    // remove zerohead dummy node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    return zeroHead;
}

// Helper function to create a linked list from an array
Node* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    Node* head = new Node(values[0]);
    Node* current = head;

    for (size_t i = 1; i < values.size(); i++) {
        current->next = new Node(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to delete a linked list and free memory
void deleteLinkedList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function to test the sortList function
int main() {
    // Example list: 2 -> 1 -> 0 -> 2 -> 1 -> 0
    vector<int> values = {2, 1, 0, 2, 1, 0};
    Node* head = createLinkedList(values);

    cout << "Original list: ";
    printLinkedList(head);

    head = sortList(head);

    cout << "Sorted list: ";
    printLinkedList(head);

    deleteLinkedList(head); // Free memory
    return 0;
}
