class Solution:

    def __init__(self):
        self.ans = []

    def helper(self, nums: List[int], i: int, lst: List[int]):
        if i>=len(nums):
            self.ans.append(lst.copy())
            return

        lst.append(nums[i])
        self.helper(nums, i+1, lst)
        
        lst.pop(len(lst)-1)
        self.helper(nums, i+1, lst)

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.helper(nums, 0, [])
        ansset = set()
        for ele in self.ans:
            ansset.add(tuple(ele))
        
        self.ans.clear()
        for el in ansset:
            self.ans.append(list(el))
        return self.ans

        