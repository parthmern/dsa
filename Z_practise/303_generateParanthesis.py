class Solution:

    def __init__(self):
        self.ans = []

    def rec(self, open, close, str):
        if open==0 and close==0:
            self.ans.append(str)
            return
        
        if open>0:
            self.rec(open-1, close, str+"(")

        if open<close:
            self.rec(open, close-1, str+")")



    def generateParenthesis(self, n: int) -> List[str]:
        #code
        self.ans = []
        self.rec(n,n, "")
        return self.ans

        