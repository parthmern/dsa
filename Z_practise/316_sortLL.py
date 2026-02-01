# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def findMid(self, head):
        slow = head
        fast = head

        while fast.next != None and fast.next.next != None:
            fast = fast.next.next
            slow = slow.next
        
        return slow

    def mergeTwoSortedLL(self, s, e):
        head = ListNode(-1)
        final = head

        while s != None and e != None:
            if s.val < e.val:
                head.next = s
                s = s.next
            else:
                head.next = e
                e = e.next
            head = head.next

        while s!= None:
            head.next = s
            s = s.next
            head = head.next

        while e!= None:
            head.next = e
            e = e.next
            head = head.next
        
        return final.next

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head
        
        midNode = self.findMid(head)
        right = midNode.next
        midNode.next = None

        left = self.sortList(head)
        rightN = self.sortList(right)

        return self.mergeTwoSortedLL(left, rightN)