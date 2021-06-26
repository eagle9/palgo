//shaun gy native, for each i, find greater from [i+1 to i+n)
//runtime 268ms, faster than 9%, mem less than 92%
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < i + n; ++j) {
                if (nums[j % n] > nums[i]) {
                    res[i] = nums[j % n];
                    break;
                }
            }
        }
        return res;
    }
};
