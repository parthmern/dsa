class Solution:
    val = 1

    def rec(self, x: float, n: int) -> float :
        if(n<=1):
            return x
        
        if int(n%2) == 0:
            return self.rec(x * x, n//2) 
        else:
            return x * self.rec(x, n-1)

    def myPow(self, x: float, n: int) -> float:
        ans = 0
        if n == 0:
            return 1
        elif(n<0):
            val = -1
            ans = self.rec(x, n*-1)
            return 1/ans
        else :
            return self.rec(x, n)
        
        
        