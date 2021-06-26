//one pass with hashmap, runtime 8ms, faster than 99.5%, mem less than 43%
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m; //number to its index
        int n = nums.size();
        
        vector<int> res(2);
        for (int i = 0; i < n; ++i) {
            int k = target - nums[i];
            
            if (m.count(k) && m[k] != i)  { //found k
                res[0] = i;
                res[1] = m[k];
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};
