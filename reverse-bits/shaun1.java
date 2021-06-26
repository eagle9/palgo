/*
Runtime: 1 ms, faster than 99.60% of Java online submissions for Reverse Bits.
Memory Usage: 38.9 MB, less than 7.32% of Java online submissions for Reverse Bits.
shaun bit idea
*/
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        //i from 0 to 32, ith bit swap with (31-i)th bit
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int b1 = n >>i &1;
            res |= b1 <<(31-i);
        }
        return res;
    }
}
