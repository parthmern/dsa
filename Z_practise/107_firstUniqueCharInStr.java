class Solution {
    public int firstUniqChar(String s) {

        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for (int i = 0; i < s.length(); i++) {
            char ele = s.charAt(i);
            int eleInt = ele;

            hm.put(eleInt, hm.get(eleInt) != null ? hm.get(eleInt) + 1 : 1);
        }

        for (int i = 0; i < s.length(); i++) {
            char ele = s.charAt(i);
            int eleInt = ele;

            if(hm.get(eleInt) == 1 ) return i;
        }

        return -1;
    }
}
