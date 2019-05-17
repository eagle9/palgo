/*idea forming
xor 
try to use bit operation to reduce repeated numbers? how? 
or and xor not
|  & ^ ~    
<< >> 
3 times,  how ????


hint by grandyang idea1
shuan coded from the idea and accepted second sub
runtime 12ms, faster than 96%, mem less than 26%
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int x: nums) {
                //sum += (x >> i) & 1; //sum ith digit ---> runtime error
                sum += (x >> i) & 1; //sum ith digit
            }
            //sum = 3*n + j,   j is ith digit of the single number
            res |=  (sum %3) << i;
        }
        return res;
    }
};
