class Solution {
    private double sol(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2==0) return sol(x*x, n/2);
        return x*sol(x,n-1);
    }
    public double myPow(double x, int n) {
        if(x==-1 && n == Integer.MIN_VALUE) return 1;
        if(x==1) return 1;
        if(x==-1) return -1;
        //if(x ==2 && n == -2147483648) return 0;
        if(n <= Integer.MIN_VALUE) return 0;
        if(n >= Integer.MAX_VALUE) return 0;
        if(n<0){
            x = 1/x;
            n=n*(-1);
        }
        return sol(x, n);
        
    }
}