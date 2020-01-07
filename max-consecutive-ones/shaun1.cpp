//shaun own idea, accepted after 1 bug fix
//runtime 32ms, faster than 94%, mem less than 97%
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start = -1; //start index of 1
        int end = -1; //end index of 1, start and end could be invalid value
        int res = 0; //max len of consecutive 1s
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (start < 0) start = i;
                end = i;
            }else { // ==0
                if (start >=0 && end >= 0)
                    res = max(res, end - start+1);
                start = -1;
            }
        }
        if (start >=0 && end >= 0)
            res = max(res, end - start+1);
        return res;
    }
};
