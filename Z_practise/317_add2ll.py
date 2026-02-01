# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def reverse(self, head):
        prev = None
        curr = head

        while curr != None:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        return prev
        

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # left = self.reverse(l1)
        # right = self.reverse(l2)

        left = l1
        right = l2

        res = ListNode(-1)
        resHead = res

        print(left.val, right.val)

        rem = 0

        while left != None and right != None:
            ans = left.val + right.val + rem
            tempRem = ans % 10
            rem = ans // 10
            newNode = ListNode(tempRem)
            res.next = newNode
            res = res.next
            left = left.next
            right = right.next

        while left!= None:
            ans = left.val + rem
            tempRem = ans % 10
            rem = ans // 10
            newNode = ListNode(tempRem)
            res.next = newNode
            res = res.next
            left = left.next

        while right!= None:
            ans = right.val + rem
            tempRem = ans % 10
            rem = ans // 10
            newNode = ListNode(tempRem)
            res.next = newNode
            res = res.next
            right = right.next


        
        if rem != 0:
            if rem >= 10:
                tr = rem % 10
                td = rem // 10
                newNode = ListNode(tr)
                res.next = newNode
                res = res.next
                newNode = ListNode(td)
                res.next = newNode
            else:
                newNode = ListNode(rem)
                res.next = newNode


        return resHead.next

            
        