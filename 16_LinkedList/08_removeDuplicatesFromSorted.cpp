#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->next != nullptr && curr->val == curr->next->val) {
                ListNode* temp = curr->next; // Store the duplicate node
                curr->next = curr->next->next; // Skip the duplicate node
                temp->next = nullptr;
                delete temp; // Free the memory of the duplicate node
            } else {
                curr = curr->next; // Move to the next node
            }
        }

        return head;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to delete a linked list and free memory
void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Test the solution
int main() {
    Solution solution;

    // Example list: 1 -> 1 -> 2 -> 3 -> 3
    vector<int> values = {1, 1, 2, 3, 3};
    ListNode* head = createLinkedList(values);

    cout << "Original list: ";
    printLinkedList(head);

    head = solution.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printLinkedList(head);

    deleteLinkedList(head); // Free memory
    return 0;
}
