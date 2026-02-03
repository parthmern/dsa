class MyStack:

    def __init__(self):
        self.q = []
        

    def push(self, x: int) -> None:
        # everytime you add you reverse q
        self.q.append(x)
        print(len(self.q))
        i=0
        while i != len(self.q)-1:
            temp = self.q.pop(0)
            self.q.append(temp)
            i+=1
            print("when i" , i , self.q)
        print(self.q)
        

    def pop(self) -> int:
        temp = self.q.pop(0)
        return temp
        

    def top(self) -> int:
        return self.q[0]
        

    def empty(self) -> bool:
        return not bool(self.q)
        


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()