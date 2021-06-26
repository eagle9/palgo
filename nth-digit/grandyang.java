
public class Solution {
    /**
     * @param n: a positive integer
     * @return: the nth digit of the infinite integer sequence
     */
     //grandyang idea, shaun code in java and commented,  beats 64%, beats 88.57%
    public int findNthDigit(int n) {
        // write your code here
        //1 - 9, 1 digit, 9 numbers, start =1
        //10 -99, 2 digits, 90 numbers, start = 10,
        //100 - 999, 3 digits, 900 numbers,  start = 100
        //use long, int does not work, why? overflow!!!
        long len = 1, cnt = 9;
        long start = 1;
        while (cnt * len < n) {
            n -= len * cnt;
            len++;
            cnt*=10;
            start *= 10;
        }
        //cnt*len >= n
        //n = 11
        //n=2, len=2, cnt = 90, start = 10
        //n =0 or 1, start + 0
        //n = 2 or 3, start +1
        start += (n-1)/len; //move to the number using remaining digit count, each number has len digits
        String t = String.valueOf(start);
        //now take the digit
        long pos = (n-1) % len;
        return t.charAt( (int) pos ) - '0';

    }
}

