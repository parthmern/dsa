class Solution {

    final static long MOD = 1000000007;

    private long pow(long x, long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return x % MOD;

        if (n % 2 == 0) {
            return pow((x * x) % MOD, n / 2);
        } else {
            return (x % MOD * pow(x, n - 1)) % MOD;
        }
    }

    public int countGoodNumbers(long n) {
        // 4
        // _ _ _ _ 
        // e o e o 
        // e -> {0, 2, 4, 6, 8} -> 5 num
        // o -> {1, 3, 5, 7} -> 4 num
        // 5*4*5*4 => 400
        // pow(5,2)*pow(4,2)

        if (n % 2 == 0) {
            long x = n / 2;
            long odd = pow(5, x) % MOD;
            long even = pow(4, x) % MOD;
            return (int) ((odd * even) % MOD);
        }

        long evenPos = (n + 1) / 2; // positions 0,2,4,...
        long oddPos = n / 2; // positions 1,3,5,...

        long evenWays = pow(5, evenPos);
        long oddWays = pow(4, oddPos);

        return (int) ((evenWays * oddWays) % MOD);

    }
}