//no extra space by lt3, use the input array itself as storage
//runtime 16ms, faster than 97%, mem less than 83%
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != INT_MAX) {
                int start = nums[i], count = 0;
                while (nums[start] != INT_MAX) {
                    int temp = start;
                    start = nums[start];
                    //temp ----> start
                    count++;
                    nums[temp] = INT_MAX;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
