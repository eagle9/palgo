//fisherlei idea, shaun has read and understood
//runtime 12ms, faster than 97.53%, mem less than 42%
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int length = nums.size();
        
        // get the xor result of the array, b ^ c
        int xor_result = 0;
        for(int i =0; i< length; i++) {
            xor_result ^= nums[i];
        }
        
        // get the K of first bit, which equals 1
        int k = 0;
        for(k =0; k< 32; k++) {
            if((xor_result>>k) & 1 == 1) {
                break;
            }
        }
        
        // use k to split the array into two part
        // xor the sub array, if the element's Kth bit also equals 1, b
        //other numbers all occur twice, if any of them shows up in the same group with b, it occurs twice. So accumulate xor with elimite it
        int xor_twice = 0;
        for(int i =0; i< length; i++) {
            if((nums[i]>>k) & 1 == 1) {
                xor_twice ^= nums[i];
            }
        }
        
        // with b, easy to get c by math
        vector<int> result = {xor_twice, xor_result ^ xor_twice };        
        return result;
    }
};

