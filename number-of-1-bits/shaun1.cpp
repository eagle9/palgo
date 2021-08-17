//shaun's own idea and code
//accepted first sub, runtime 4ms, faster than 97%, mem less than 35%
class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            count += n & 1;
            n >>=1; 
        }
        return count;
    }
};

/*
lt idea
The key idea here is to realize that for any number n, doing a bit-wise AND of n and n - 1 flips the least-significant 1-bit in n to 0. Why? Consider the binary representations of n and n - 1, draw a picture you will understand. 

but this idea is not easy/natural to be formed. 
runtime 4ms, faster than 97%, mem less than 65%

*/
class Solution {
public:
    
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count++;
            n &= n-1;
        }
        return count;
    }
};
