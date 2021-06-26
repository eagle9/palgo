//grandyang idea, 1 main loop with a sub loop to deal with consecutive sub array
//runtime 0ms, faster than 100%, mem less than 61%
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, n = nums.size();
        while (i < n) {
            //start from i, expand consecutive seq, i --- i+j
            int j = 1;
            //while (i + j < n && nums[i + j] - nums[i] == j) ++j;  //bug 1 -- signed integer overflow
            while (i + j < n && nums[i] + j == nums[i + j]) ++j;  
            //while (i + j < n && (long)nums[i + j] - nums[i] == j) ++j; //bug 
            
            res.push_back(j <= 1 ? to_string(nums[i]) : to_string(nums[i]) + "->" + to_string(nums[i + j - 1]));
            //update i
            i += j;
        }
        return res;
    }
};
