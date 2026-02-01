# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def length(self, head):
        temp = head
        c = 0
        while temp!=None:
            c+=1
            temp = temp.next

        return c

    def reverse(self, head):
        prev = None
        curr = head

        while curr != None:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        return prev
        

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        len = self.length(head)
        first = head

        if len < k:
            return head
        
        last = first
        count = k

        while count != 1:
            last = last.next
            count-=1
            
        nextFirst = last.next

        last.next = None
            
        revHead = self.reverse(first)

        head.next = self.reverseKGroup(nextFirst, k)

        return revHead