class Solution:

    def __init__(self):
        self.ans = []

    def helper(self, candidates: List[int], index: int, lst: List[int], curr_sum:int, target: int):
        print(lst, curr_sum, len(candidates))
        if curr_sum >= target:
            if curr_sum == target:
                self.ans.append(lst.copy())
            return
        
        for i in range(index, len(candidates)):
            if i > index and candidates[i] == candidates[i-1]:
                continue
            if curr_sum+candidates[i] > target :
                break

            lst.append(candidates[i])
            self.helper( candidates, i+1, lst, curr_sum+candidates[i], target)
            lst.pop(len(lst)-1 )
            # if curr_sum+candidates[i] >= target :
            #     break
           

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        sum=0
        for ele in candidates:
            sum+=ele
        if sum<target:
            return self.ans
        self.helper(candidates, 0, [], 0, target)
        ansNoDup = set()
        for lst in self.ans:
            ansNoDup.add(tuple(lst))
        self.ans.clear()
        for ele in ansNoDup:
            self.ans.append(list(ele))
        return self.ans
        