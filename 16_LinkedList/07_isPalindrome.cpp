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
    ListNode* findMiddle(ListNode* head) {
        // Find the middle of the linked list using slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode*& head) {
        // Reverse the linked list starting from the given head
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;

        while (curr != nullptr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Step 1: Find the middle of the list
        ListNode* middle = findMiddle(head);

        // Step 2: Reverse the second half of the list
        ListNode* reverseKaHead = reverse(middle);
        //middle->next = reverseKaHead;

        // Step 3: Compare the first half and the reversed second half
        ListNode* temp1 = head;
        ListNode* temp2 = reverseKaHead;
        bool isPalin = true;

        while (temp2 != nullptr) {
            if (temp1->val != temp2->val) {
                isPalin = false;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }


        return isPalin;
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

// Helper function to delete the linked list and free memory
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

    // Example list: 1 -> 2 -> 3 -> 2 -> 1
    vector<int> values = {1, 2, 3, 2, 1};
    ListNode* head = createLinkedList(values);

    if (solution.isPalindrome(head))
        cout << "The linked list is a palindrome." << endl;
    else
        cout << "The linked list is NOT a palindrome." << endl;

    deleteLinkedList(head); // Free memory
    return 0;
}
