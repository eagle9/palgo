public class Solution {
    /**
     * @param num: an integer
     * @return: whether the integer is a power of 4
     */
     //grandyang idea, beats 91%
    public boolean isPowerOfFour1(int num) {
        // Write your code here
        
        return num > 0 && (num &(num -1)) == 0 && (num-1) % 3 == 0;
        //use power of two idea, add one more condition 
    }
    
    
    //trivial solution, beats 76%
    public boolean isPowerOfFour(int num) {
        if (num < 1) return false;
        while (num % 4 == 0) {
            num = num/4;
        }
        return num == 1;
    }
}
