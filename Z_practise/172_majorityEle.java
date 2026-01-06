class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int ele: nums){
            if(map.get(ele) == null){
                map.put(ele, 1);
            }else{
                map.put(ele, map.get(ele)+1);
            }
        }

        for(int key: map.keySet()){
            System.out.println("key "+ key + "->" + map.get(key));
            if(map.get(key) > nums.length/2) return key;
        }

        return -1;
    }
}