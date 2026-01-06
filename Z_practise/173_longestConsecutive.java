

class Solution {

    // Function to return length of longest subsequence of consecutive integers.
    public int longestConsecutive(int[] arr) {

        if (arr.length == 0) return 0;

        Arrays.sort(arr);

        int longest = 1;
        int curr = 1;

        for (int i = 1; i < arr.length; i++) {

            // skip duplicates
            if (arr[i] == arr[i - 1]) {
                continue;
            }

            // consecutive number
            if (arr[i] == arr[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }

            longest = Math.max(longest, curr);
        }

        return longest;
    }
}
