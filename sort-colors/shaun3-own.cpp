//shaun's own idea, with a bug fix accepted
//runtime 4ms, faster than 92%, mem less than 7%
//idea implemented, it is key to find bugs running the code with sample case
class Solution {
public:
    void sortColors(vector<int>& nums) {
		//i0 -- index to place 0,  i2 -- index to store 2
        int i0 = 0, i2 = nums.size()-1;
        int i = 0;
        while (i <= i2) {
            if (nums[i] == 2) {
				//put 2 to where it belongs, now i stores the element to be processed
				//update i2
                swap(nums[i], nums[i2--]);
            }
            else if (nums[i] == 0) {
				//store 0 to where it belongs, now i stores the element to be processed
                if (i != i0)
                    swap(nums[i], nums[i0++]);
                else
                    i++;
            }else {// nums[i] == 1
                i++;
            }
            
        }
    }
};
