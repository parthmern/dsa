# Node class
''' class Node:

    def __init__(self, new_data):
        self.data = new_data
        self.next = None 
'''

# Stack class template
class myStack:

    def __init__(self):
        # Initialize your data members
        self.head = None
        self.tail = None
        

    def isEmpty(self):
        # Check if the stack is empty
        return self.head == None and self.tail == None
        

    def push(self, x):
        # Adds element x to the top of the stack
        newNode = Node(x)
        if self.isEmpty():
            self.head = newNode
            self.tail = newNode
        else:
            self.tail.next = newNode
            self.tail = newNode
        

    def pop(self):
        # Removes an element from the top of the stack
        if not self.isEmpty():
            prev = self.head
            curr = self.head.next
            
            if curr == None:
                self.head = None
                self.tail = None
                return
            
            while curr.next != None:
                prev = curr
                curr = curr.next
            
            prev.next = None
            self.tail = prev
        


    def peek(self):
        # Returns the top element of the stack
        # If the stack is empty, return -1
        if self.isEmpty():
            return -1
        else:
            return self.tail.data


    def size(self):
        # Returns the current size of the stack
        if self.isEmpty():
            return 0
        prev = self.head
        curr = self.head.next
        count = 1
        
        while curr != None:
            #print("counitn", curr.data)
            prev = curr
            curr = curr.next
            count+=1
            
        return count
        