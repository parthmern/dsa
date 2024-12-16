#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int getLen(ListNode* head) {
    int len = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL) {
        // Linked list is empty
        return head;
    }

    if (k > getLen(head)) {
        // Invalid k value
        return head;
    }

    // Reverse logic
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = curr->next;
    int count = 0;
    ListNode* forward = NULL;

    while (count < k && curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Recursive reversal for remaining nodes
    if (forward != NULL) {
        head->next = reverseKGroup(forward, k);
    }

    // Return the new head of the modified linked list
    return prev;
}

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // Group size to reverse

    ListNode* head = createLinkedList(arr, n);

    cout << "Original Linked List: \n";
    printLinkedList(head);

    head = reverseKGroup(head, k);

    cout << "Modified Linked List after reversing in groups of " << k << ": \n";
    printLinkedList(head);

    return 0;
}
