// https://leetcode.com/problems/intersection-of-two-arrays/

import java.util.*;

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {

        Set<Integer> ans = new HashSet<>();

        int len1 = nums1.length;
        int len2 = nums2.length;

        if (len1 >= len2) {
            for (int e1 : nums1) {
                for (int i = 0; i < len2; i++) {
                    if (e1 == nums2[i]) {
                        ans.add(e1);
                        break;
                    }
                }
            }
        } else {
            for (int e2 : nums2) {
                for (int i = 0; i < len1; i++) {
                    if (e2 == nums1[i]) {
                        ans.add(e2);
                        break;
                    }
                }
            }
        }

        int[] result = new int[ans.size()];
        int i = 0;
        for (int n : ans) result[i++] = n;

        // int[] result = ans.stream().mapToInt(Integer::intValue).toArray();

        return result;
    }
}
