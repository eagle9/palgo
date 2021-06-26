/*
grandyang math idea, no string conversion
get idea from example:
如 1221 这个数字，如果 计算 1221 / 1000， 则可得首位1， 如果 1221 % 10， 则可得到末尾1，进行比较，然后把中间的22取出继续比较

runtime 8ms, faster than 99%, mem less than 92%
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true; //single digit
        int div = 10;
        //get largest divisor for left digit
        while (x / div >= 10) div *= 10;
        
        while (x > 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right) return false;
            //1221  ---> 22
            //1221 % 1000 = 221, remove left digit
            // 221 /10 = 22, remove right digit
            x = (x % div) / 10;
            
            //remove 2 0's from div, not 1 zero
            div /= 100;
        }
        return true;
    }
};
