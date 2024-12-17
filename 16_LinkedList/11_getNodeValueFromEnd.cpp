// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem

void func(SinglyLinkedListNode* head, int& pos, int& ans){
    
    // base
    if(head == NULL){
        return;
    }
    
    // head = head->next; // giving error
    func(head->next, pos, ans);
    
    if(pos == 0){
        ans = head->data;
    }
    pos--;
    
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    
    int ans = -1;
    func(llist, positionFromTail, ans);
    return ans;
}