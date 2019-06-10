/* Huahua idea with prefix sum and hash table
similar to laioffer idea, laioffer has better explanation


 Runtime: 44 ms, faster than 65.83.01%
mem less than 29% 

try naive loop first, then naive loop with prefix sum, then hashtable
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        unordered_map<int, int> mSum{{0,1}}; //sum to its count
        int prefixSum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            
            // k= prefixSum at i - prefixSum at j < i????
            count += mSum[prefixSum - k];
            ++mSum[prefixSum];
        }
        return count;
    }
};

