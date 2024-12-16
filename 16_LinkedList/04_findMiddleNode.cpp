#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        if(head == NULL){
            // cout << "Linked list is empty";
            return head;
        }

        if(head->next == NULL){
            return head;
        }

        // Linked list has more than one node
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL && fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        
        // cout << "Middle node is " << slow->val;
        return slow;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createLinkedList(arr, n);
    
    cout << "Original Linked List: ";
    printLinkedList(head);

    Solution solution;
    ListNode* middle = solution.middleNode(head);

    cout << "Middle Node: " << middle->val << endl;

    return 0;
}
