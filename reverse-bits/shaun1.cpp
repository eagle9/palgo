//grandyang idea, similar to my own idea, shaun coded from idea
//accepted first sub
//runtime 4ms, faster than 97%, mem less than 10%
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //i from 0 to 32, ith bit swap with (31-i)th bit
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int b1 = (n >>i)&1;
            res |=  b1<<(31-i);
        }
        return res;
    }
};
