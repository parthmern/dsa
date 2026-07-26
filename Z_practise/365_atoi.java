class Solution {

    static final int INT_MIN_VAL = Integer.MIN_VALUE;
    static final int INT_MAX_VAL = Integer.MAX_VALUE;

    int sign = 1;

    private long sol(String s, int i, long num){

        if(i<s.length() && Character.isDigit(s.charAt(i)) ){
            
            if (num > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (num < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            num = num * 10 + (s.charAt(i) - '0');
        }else{
            return num;
        }

        return sol(s, i+1, num);

    }

    public int myAtoi(String s) {

        int i = 0;
        while(i<s.length() && s.charAt(i) == ' ' ) i++;
        
        if(i>=s.length()) return 0;

        char ch = s.charAt(i);
        if(ch == '+'){
            sign = 1;
            i++;
        }
        if(ch == '-'){
            sign = -1;
            i++;
        }

        long num = 0;

        long ans = sol(s, i, 0);

        ans *= sign;

        if (ans > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        if (ans < Integer.MIN_VALUE) return Integer.MIN_VALUE;

        return (int) ans;
        
    }
}