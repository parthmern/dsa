class Solution:

    def __init__(self):
        self.ans = []

    def isPalindrome(self, s: str, i: int, j: int) -> bool:
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

    def helper(self, s: str, index: int, lst: List[str]):
        if index == len(s):
            self.ans.append(lst.copy())
            return

        for i in range(index, len(s)):
            if self.isPalindrome(s, index, i):
                lst.append(s[index:i+1])
                self.helper(s, i+1, lst)
                lst.pop()

    def partition(self, s: str) -> List[List[str]]:
        self.ans.clear()
        self.helper(s, 0, [])
        return self.ans
