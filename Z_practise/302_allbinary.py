class Solution:
    
    def __init__(self):
        self.ans = []
    
    def rec(self, i, str):
        if i==0:
            self.ans.append(str)
            return
        
        self.rec( i-1, str+"0")
        self.rec( i-1, str+"1")
    
    def binstr(self, n):
        # code here
        self.rec( n, "")
        return self.ans
        