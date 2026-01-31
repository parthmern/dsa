'''
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		self.prev = None

'''

class Solution:
    def insertAtPos(self, head, p, x):
        # Code Here
        count = 0
        temp = head
        while count != p:
            temp = temp.next
            count+=1
        
        newNode = Node(x)
        newNode.prev = temp
        newNode.next = temp.next
        if temp.next != None:
            temp.next.prev = newNode
        temp.next = newNode
        return head
        