public class Solution {
    /**
     * @param n: an integer
     * @return: if n is a power of three
     */
     
     //using loop, beats 94%
    public boolean isPowerOfThree1(int n) {
        // Write your code here
        
        if (n < 1) return false;
        while (n % 3 == 0) {
            n = n/3;
        }
        return n == 1;
    }
    
    //beats 94%
    public boolean isPowerOfThree2(int n) {
        
        if(n <= 0)return false;
        if(1162261467%n == 0) //largest 3^n with 31 bits
            return true;
        else
            return false;
                        
        
    }
    //beats 94%
    public boolean isPowerOfThree(int n) {
        double res;
        //res = Math.log(n)/Math.log(3);   natural log wrong answer
        res = Math.log10(n)/Math.log10(3);
        if(res- (int)res == 0)
            return true;
        else
            return false;
    }
    
}
