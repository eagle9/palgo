/*
shaun own idea and code 
cutting: consider put all non zero elements to its expected position, or storeIndex
0 (1)1 0 (3) 12
1  3  12 00

my first thought is to look at zero and put them into expected position, end of array
does not work out, i quickly changed my direction or cutting angle

runtime 12ms, faster than 98%, mem less than 58%
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int storeIndex = 0; //store index for non zero
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) nums[storeIndex++] = nums[i];
        }
        for (int i = storeIndex; i < n; ++i) {
            nums[i] = 0;
        }
    }
};
