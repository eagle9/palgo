/*
Runtime: 12 ms, faster than 99.64% of C++ online submissions for Jump Game II.
Memory Usage: 10.7 MB, less than 100.00% of C++ online submissions for Jump Game II.

grandyang greedy idea, how to come up with the idea???? and make sure it is correct???

*/
class Solution1 {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), i = 0, cur = 0;
        while (cur < n - 1) {
            ++res;
            int pre = cur;
            for (; i <= pre; ++i) {
                cur = max(cur, i + nums[i]);
            }
            if (pre == cur) return -1; // May not need this
        }
        return res;
    }
};
/*
Runtime: 16 ms, faster than 87.90% of C++ online submissions for Jump Game II.
Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Jump Game II.
grandyang idea 2
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), last = 0, cur = 0;
        for (int i = 0; i < n - 1; ++i) {
            cur = max(cur, i + nums[i]);
            if (i == last) {
                last = cur;
                ++res;
                if (cur >= n - 1) break;
            }
        }
        return res;
    }
};
