'''
class Node:
    def __init__(self, d):
        self.data=d
        self.next=None
        self.bottom=None
        
'''

class Solution:
    
    def findMid(self, head):
        slow = head
        fast = head.bottom
    
        while fast and fast.bottom:
            slow = slow.bottom
            fast = fast.bottom.bottom
    
        return slow

    
    def merge(self, a, b):
        if a is None:
            return b
        if b is None:
            return a
    
        if a.data <= b.data:
            result = a
            result.bottom = self.merge(a.bottom, b)
        else:
            result = b
            result.bottom = self.merge(a, b.bottom)
    
        result.next = None   # IMPORTANT: keep next clean
        return result

    
    def mergeSort(self, head):
        if head is None or head.bottom is None:
            return head
    
        mid = self.findMid(head)
        right = mid.bottom
        mid.bottom = None
    
        leftSorted = self.mergeSort(head)
        rightSorted = self.mergeSort(right)
    
        return self.merge(leftSorted, rightSorted)

    
    def flatten(self, root):
        # code here
        
        temp = root
        
        while temp != None:
            first = temp
            nextNode = first.next
            first.next = None
            
            second = first
            while second != None and second.bottom != None:
                second = second.bottom
                
            
            second.bottom = nextNode
            # if nextNode != None:
            #     print("seocnd bottom ", second.data, " connecting to ", nextNode.data)
            temp = nextNode
            
        return self.mergeSort(root)
            
        
        
        
        
        