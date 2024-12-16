#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    bool isCycled = false;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow) {
            slow = head;
            isCycled = true;
            break;
        }
    }

    while (fast != NULL && slow != fast) {
        fast = fast->next;
        slow = slow->next;

        if (fast == slow) {
            break;
        }
    }

    return isCycled ? slow : NULL;
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

// Helper function to create a cycle in the linked list
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;

    ListNode* temp = head;
    ListNode* cycleNode = nullptr;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos) {
            cycleNode = temp;
        }
        temp = temp->next;
        index++;
    }

    // Create the cycle
    temp->next = cycleNode;
}

int main() {
    int arr[] = {3, 2, 0, -4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pos = 1; // Position where the cycle starts (0-based index, -1 means no cycle)

    ListNode* head = createLinkedList(arr, n);
    createCycle(head, pos);

    ListNode* cycleNode = detectCycle(head);

    if (cycleNode != NULL) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
