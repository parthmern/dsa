class Solution(object):
    def maxDepth(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        ans = 0
        for char in s:
            if char == "(":
                count+=1
                ans = max(ans, count)
            elif char == ")":
                count-=1
                
        return ans