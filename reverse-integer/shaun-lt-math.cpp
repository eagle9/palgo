/*

123
digit = 3
x = 12      res = 0*10+3 = 3
digit = 2
x = 1       res = 3*10 + 2
digit = 1  
x = 0       res = 32*10 + 1 = 321

note: -7 % 10 = -7
x = -123, res = 0
digit = -3, x = -12, res = 0*10 + -3 = -3
digit = -2, x = -1, res = -3*10 + -2 = -32
digit = -1, x = 0, res = -32*10 + -1 = -321

32 bit integer, high bit is sign, 2^31 = 2147483648
1000 = 8 = 2^3
1.. 31(0) = 2^31, positive max = 2^31-1 = 2147483647
negative signed integers are stored in what is called two's complement.

The two's complement of an N-bit number x is defined as 2^N - x. For example, the two's complement of 8-bit 1 is  2^8 - 1, or 1111 1111. The two's complement of 8-bit 8 is 2^8 - 8, which in binary is 1111 1000. This can also be calculated by flipping the bits of x and adding one.
x no sign binary represeation, x= -8, 00001000, flipping all 1111,0111 + 1 =
11111000 
min integer INT_MIN = ?  1111 = -1, 2^4 -x = 1000, x = 2^4 - 1000 = 8 with - sign
so for 4 bit signed integer, the range is -8 to 7(0111)
for 32 bit signed integer, the range is -2^31, 2^31-1

Values of INT_MAX and INT_MIN may vary from compiler to compiler. Following are typical values in a compiler where integers
are stored using 32 bits.

Value of INT_MAX is +2147483647.  INT_MAX/10 = 214748364
Value of INT_MIN is -2147483648.


lt idea with mod and division to get digits
runtime 0ms, faster 
res = res*10 + digit to construct number
check before overflow
shaun fully understands and get all details clear
*/
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int digit = x % 10; //get digit from low to high
            x /= 10;
            //check before overflow, res will be res*10 + digit
            //why digit > 7 overflow? INT_MAX ends with 7, INT_MAX/10 = 214748364
            if (res > INT_MAX/10 || (res == INT_MAX / 10 && digit > 7)) return 0;
            //why 
            if (res < INT_MIN/10 || (res == INT_MIN / 10 && digit < -8)) return 0;
            res = res * 10 + digit;
        }
        return res;
    }
};
