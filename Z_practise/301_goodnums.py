class Solution:
    def rec(self, x, n, MOD):
        if n == 0:
            return 1
        if n == 1:
            return x % MOD
        
        if n % 2 == 0:
            half = self.rec(x, n // 2, MOD)
            return (half * half) % MOD
        else:
            return (x * self.rec(x, n - 1, MOD)) % MOD

    def countGoodNumbers(self, n: int) -> int:
        MOD = 10**9 + 7
        odd = (n + 1) // 2
        even = n // 2
        
        return (self.rec(5, odd, MOD) * self.rec(4, even, MOD)) % MOD