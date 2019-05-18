//grandyang idea, shaun understood and coded from the idea with checks
//runtime 0ms, faster than 100%, mem less than 13%
/*idea forming:
without carry:
0+1 = 1
1+0 = 1    ===> xor  ^
0+0 = 0
1+1 = 0
carry:
1+1 -> 1
0+0 ->0           ===> bit and &,   needs to shift left 1 bit
1+0, 0+1 -> 0
*/
class Solution1 {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        int sum = a ^ b;
        int carry = (a & b & 0x7fffffff)<<1;
        return getSum(sum, carry);
    }
};

//recursion to iteration, runtime 0ms, faster than 100%, mem less than 65%
class Solution {
public:
    int getSum(int a, int b) {
        while (b !=0) {
            int sum = a ^ b;
            int carry = (a & b & 0x7fffffff)<<1;
            a = sum;
            b = carry;
        }
        return a;
    }
};
