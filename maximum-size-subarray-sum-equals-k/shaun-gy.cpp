//runtime 32ms, faster than 90%, mem less than 80%
//time O(n), space O(n)
//gy showed net god's idea with prefix sum and hash, shaun understood
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        //store prefixSum to its ending index
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) res = i + 1;
            //0 ... j     sum to sum-k
            //0 ...     i sum to sum
            //j+1 ... i sum to k, len = i-j
            else if (m.count(sum - k)) res = max(res, i - m[sum - k]);
            //store prefix sum to its ending index
            if (!m.count(sum)) m[sum] = i;
        }
        return res;
    }
};
