class Solution:
    def myAtoi(self, s: str) -> int:
        ans = 0
        multi = 1
        isChanged = False
        isSpacedDone = False
        for ele in s:
            print(f"multi ${multi} for {ele}")
            if ele == " ":
                if(isSpacedDone) :
                    break
                else:
                    continue
            elif ele == "-" or ele == "+":
                if isChanged :
                    break
                elif ele == "-":
                    multi = -1 
                isChanged = True  
                isSpacedDone = True    
            else:
                isSpacedDone = True
                if ele.isdigit() :
                    isChanged = True 
                    ans = ans * 10 + int(ele)
                else :
                    break
        ans = int(ans) * multi

        print(ans)
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        if ans < INT_MIN:
            return INT_MIN
        if ans > INT_MAX:
            return INT_MAX
        return ans