class Solution {
    int maxLength(int arr[]) {

        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(0, -1);  

        int sum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];

            if (mp.containsKey(sum)) {
                maxLen = Math.max(maxLen, i - mp.get(sum));
            } else {
                mp.put(sum, i);
            }
        }

        return maxLen;
    }
}
