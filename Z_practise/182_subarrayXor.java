class Solution {
    public long subarrayXor(int arr[], int k) {
        long count = 0;
        int prexor = 0;

        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);

        for (int i = 0; i < arr.length; i++) {

            prexor = prexor ^ arr[i];

            int target = prexor ^ k; // prexor ^ target = k → subarray xor = k

            if (map.containsKey(target)) {
                count = count + map.get(target); 
            }

            map.put(prexor, map.containsKey(prexor) ? map.get(prexor)+1 : 1);
        }

        return count;
    }
}
