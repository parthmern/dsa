// https://leetcode.com/submissions/detail/1481349328/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    // Node* helper(Node* head, unordered_map<Node*, Node*> &mp){

    //     if(head==NULL) return NULL;
    
    //     Node* newHead = new Node(head->val);
    //     mp[head] = newHead;
    //     newHead->next = helper(head->next, mp);

    //     if(head->random){
    //         // agar puranewala head kahi random point kar rha he
    //         newHead->random = mp[head->random];
    //     }

    //     return newHead;
    // }

    Node* copyRandomList(Node* head) {
        
        // unordered_map<Node*, Node*> mp;
        // return helper(head, mp);

        if(!head) return 0;

        // 1)clone A(old) -> A'(new)
        Node* it = head;

        while(it!=NULL){
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }

        // 2) assign random links of A' with the help of A
        it = head;
        while(it){
            Node* clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : NULL;
            it = it->next->next;
        }

        // 3) detach both old and new
        it = head;
        Node* clonedHead = it->next;

        while(it){
            Node* clonedNode = it->next;
            it->next = it->next->next;
            if(clonedNode->next){
                clonedNode->next = clonedNode->next->next;
            }
            it = it->next;
        }

        return clonedHead;




    }
};