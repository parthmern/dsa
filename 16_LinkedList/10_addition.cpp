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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reverse
        l1 = reverse(l1);
        l2 = reverse(l2);

        // calculate sum
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            if (ansHead == NULL) {
                // first node
                ansHead = newNode;
                ansTail = newNode;
            } else {
                ansTail->next = newNode;
                ansTail = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        // head1 list ki length head2 list se jyada hogi
        while (l1 != NULL) {
            int sum = l1->val + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            l1 = l1->next;
        }

        // head2 list ki length head1 se jyada he
        while (l2 != NULL) {
            int sum = l2->val + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
            l2 = l2->next;
        }

        // if still carry is there means notZero
        while (carry != 0) {
            int sum = carry;
            int digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);
            ansTail->next = newNode;
            ansTail = newNode;
        }

        ansHead = reverse(ansHead);
        return ansHead;
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
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Example inputs
    vector<int> list1 = {7, 2, 4, 3}; // Represents the number 7243
    vector<int> list2 = {5, 6, 4};    // Represents the number 564

    // Create linked lists
    ListNode* l1 = createLinkedList(list1);
    ListNode* l2 = createLinkedList(list2);

    // Add the two numbers
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result
    printLinkedList(result);

    return 0;
}
