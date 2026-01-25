import java.util.*;

class Solution {

    List<String> ans;

    Solution() {
        ans = new ArrayList<>();
    }

    private void helper(String num, int target, int index, String temp, long currSum, long prev) {

        if (index == num.length()) {
            if (currSum == target) {
                ans.add(temp);
            }
            return;
        }

        for (int j = index; j < num.length(); j++) {

            if (j > index && num.charAt(index) == '0') break;

            String part = num.substring(index, j + 1);
            long value = Long.parseLong(part);

            if (index == 0) {
                helper(num, target, j + 1, part, value, value);
            } else {
                // +
                helper(num, target, j + 1, temp + "+" + part, currSum + value, value);

                // -
                helper(num, target, j + 1, temp + "-" + part, currSum - value, -value);

                // *
                helper(num, target,j + 1, temp + "*" + part, currSum - prev + (prev * value), prev * value);
            }
        }
    }

    public List<String> addOperators(String num, int target) {
        ans.clear();
        helper(num, target, 0, "", 0, 0);
        return ans;
    }
}
