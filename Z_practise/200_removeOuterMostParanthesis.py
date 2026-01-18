class Solution(object):
    def removeOuterParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        i=0
        bal=0
        ans = []
        while i < len(s)-1:
            
            if s[i] == ")":
                bal-=1
            
            if bal!=0:
                ans.append(s[i])

            if s[i] == "(":
                bal+=1

            i+=1
            
        return "".join(ans)