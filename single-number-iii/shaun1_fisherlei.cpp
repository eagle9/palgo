//fisherlei idea, shaun has read and understood
//runtime 12ms, faster than 97.53%, mem less than 42%
//cutting, still use xor, we can two single number's bit xor result
//find the first set bit of xor_result, which comes from one of the single number
//use this set bit to break the numbers into two groups, get xor for group1, xor will be one of the single number, then xor ^ xor_result will be the other single number
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int length = nums.size();
        
        // get the xor result of the array, b ^ c
        int xor_result = 0;
        for(int i =0; i< length; i++) {
            xor_result ^= nums[i];
        }
        
        // get the bit index(0-32) of the first set bit of xor_result
        //this set bit either comes from single number a or b, makes sense right? 
        int k = 0;
        for(k =0; k< 32; k++) {
            if((xor_result>>k) & 1 == 1) {
                break;
            }
        }
        
        // use kth set bit to split the array into two part
        // kth bit set group1,  kth bit not set group2
        
        // xor the sub array, if the element's Kth bit also equals 1, b
        //other numbers all occur twice, if any of them shows up in the same group with b, it occurs twice. So accumulate xor with elimite it
        int xor_twice = 0;
        for(int i =0; i< length; i++) {
            //xor for group1 number only
            if((nums[i]>>k) & 1 == 1) {
                xor_twice ^= nums[i];
            }
        }
        //now xor_twice will be one of the singler number
        //one clever trick is to use computed xor_result and xor_twice to get the other single number
        // with b, easy to get c by math
        vector<int> result = {xor_twice, xor_result ^ xor_twice };        
        return result;
    }
};

