//shaun original idea and code, accepted first sub
//runtime 16ms, faster than 99%, mem less than 100%
//this time i read the problem description and tested with 1 case
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;   //index for non zero elements
        
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] != 0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }
    }
};
