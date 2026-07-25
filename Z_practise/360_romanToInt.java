class Solution {
    public int romanToInt(String s) {

        Map<Character, Integer> mp = new HashMap<>();

            mp.put('I', 1);
            mp.put('V', 5);
            mp.put('X', 10);
            mp.put('L', 50);
            mp.put('C', 100);
            mp.put('D', 500);
            mp.put('M', 1000);

            mp.put('0', 0); // dummy
        

        int sum = 0;

        for(int i=0; i<s.length(); i++){
            Character ch = s.charAt(i);
            Character nextCh = i!=s.length()-1 ? s.charAt(i+1) : '0';

            if(mp.get(ch) < mp.get(nextCh)) sum -= mp.get(ch);
            else sum += mp.get(ch);
        }

        return sum;
        
    }
}