//grandyang naive get digits and sum
//runtime 0ms, faster than 100%, mem less than 42%
class Solution {
public:
    int addDigits(int num) {
        //when numm has >=2 digits
        while (num / 10 > 0) {
            //add all digits of num
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            //update num with the sum of digits
            num = sum;
        }
        return num;
    }
};
