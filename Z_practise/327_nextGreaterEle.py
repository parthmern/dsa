class Solution:
    def nextLargerElement(self, arr):
        # code here
        n = len(arr)
        
        ans = [-1] * n
        
        st = []
        st.append(-1)
        
        for i in range(n-1, -1, -1):
            
            curr = arr[i]
            
            while st[-1] <= curr and st[-1] != -1:
                st.pop()
                
            ans[i] = st[-1]
            
            st.append(curr)
            
        
        return ans