//shaun 2nd try with consult grandyang solution
//runtime 7ms, faster than 100%, make it simpler with positive n
class Solution {
    public double myPow(double x, int n) {
        
        //if (n < 0) return 1/helper(x, -n); 
        if (n < 0) return helper(1/x, -n); 
        else
            return helper(x,n);
        
    }
    private double helper(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n % 2 == 0)
            return helper(x*x, n/2);
        else 
            return x*helper(x*x, n/2);
    }
}

//shaun's first try, right idea, loose with details, runtime error
class Solution0 {
    public double myPow(double x, int n) {
        if (x < 0.00001) return 0;
        if (n < 0) return myPow(1.0/x, -n); 
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n % 2 == 0)
            return myPow(x*x, n/2);
        else 
            return x*myPow(x*x, n/2);
    }
}
