class Solution:

    def __init__(self):
        self.ans = []
    
    def helper(self, index: int, lst: List[int], curr_sum: int, target: int, k: int):
        if curr_sum == target and len(lst) == k:
            self.ans.append(lst.copy())
            return
        
        if len(lst) > k:
            return
        
        for i in range(index, 10):
            lst.append(i)
            self.helper(i+1, lst, curr_sum+i, target, k)
            lst.pop(len(lst)-1) 

    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        # range is from 1-->9
        self.helper(1, [], 0, n, k)
        return self.ans
        