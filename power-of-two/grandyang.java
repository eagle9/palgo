public class Solution {
    /**
     * @param n: an integer
     * @return: if n is a power of two
     */
     //grandyang bit shift idea, shaun code from memory of the idea, beats 87%
    public boolean isPowerOfTwo1(int n) {
        // Write your code here
        int cnt  = 0; //
        while (n > 0) {
            //if (n & 1 == 1) key point, put bit operation inside (), low precedence
            if ((n & 1) == 1)
                cnt++;
            n = n>>1;
        }
            
        return cnt == 1;
    }
    
    //grandyang math and bit idea, beats 91%
    public boolean isPowerOfTwo(int n) {
        
        return (n  & (n-1)) == 0;
        //return n > 0 && (n  & (n-1)) == 0;
    }
}
