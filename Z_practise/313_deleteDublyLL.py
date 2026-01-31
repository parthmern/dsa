"""
class Node:
    def __init__(self, d):
        self.data = d
        self.prev = None
        self.next = None
"""

class Solution:
    def delPos(self, head, x):
        if x == 1:
            
            head = head.next
            head.prev = None
            return head
        # code here
        temp = head
        count = 1
        while count != x:
            temp = temp.next
            count+=1
            
            
        #print(temp.data, temp.next.data , temp.prev.data)
        if temp.prev != None:
            temp.prev.next = temp.next
            
        if temp.next != None:
            temp.next.prev = temp.prev
        
        
        
        #if temp.prev != None:
            
        
        return head
        