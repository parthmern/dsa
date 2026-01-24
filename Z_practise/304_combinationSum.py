class Solution:

    def rec(self, candidates: List[int], i: int, ans: List[List[int]] ,lst: List[int], currSum: int, target: int):
        # print(lst, currSum)
        if currSum == target:
            temp=lst.copy()
            temp.sort()
            ans.append(temp)
            return
        if currSum > target:
            return
        
        for j in range(i, len(candidates)):
            lst.append(candidates[j])
            self.rec(candidates, i, ans, lst, currSum+candidates[j], target)
            lst.pop(len(lst)-1)
        



    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        for i in range(len(candidates)):
            lst =[]
            lst.append(candidates[i])
            self.rec(candidates, i, ans, lst, candidates[i], target)

        setAns = set()
        for lst in ans:
            setAns.add(tuple(lst))
        #print(setAns)

        ans.clear()

        for tup in setAns:
            ans.append(list(tup))

        return ans

        