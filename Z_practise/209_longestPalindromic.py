def reverse(s: str) -> str:
    return s[::-1]   # slice-based reverse

class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        for i in range(len(s)):
            for j in range(i, len(s)):
                substring = s[i:j+1]
                if substring == reverse(substring) and len(substring) > len(ans):
                    ans = substring
        return ans  