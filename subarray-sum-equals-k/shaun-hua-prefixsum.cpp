/* Huahua idea with prefix sum and hash table
similar to laioffer idea, laioffer has better explanation
cutting prefixsum and hashtable
Running Prefix sum

 Runtime: 52 ms, faster than 63.01% of C++ online submissions for Subarray Sum Equals K.
Memory Usage: 18.1 MB, less than 100.00% of C++ online submissions for Subarray Sum Equals K.

shaun modified with prefixSum - k in mSum hashtable check
runtime 28ms, faster than 98%, mem less than 38%


*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        unordered_map<int, int> mSum{{0,1}}; //hashtable: prefixsum to its count
        int prefixSum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            
            // k= prefixSum ending at i - prefixSum ending at j < i?
            //prefixSum_j = prefixSum - k
            // if prefixSum_j in mSum, then found mSum[] candidates
            //  not in, mSum[] will be 0
            //count += mSum[prefixSum - k];
            if (mSum.find(prefixSum -k ) != mSum.end()) {
                count += mSum[prefixSum - k];
            }
            ++mSum[prefixSum];
        }
        return count;
    }
};

