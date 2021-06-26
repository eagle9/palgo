//shaun own idea and accepted second sub after a simple debug
//runtime 28ms, faster than 95%, mem less than 20%
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m; //number to its index
        
        for (int i = 0; i < nums.size(); ++i) {
            if (!m.count(nums[i])) { //not in map yet
                m[nums[i]] = i;
            }else { //found duplicate
                int iprev = m[nums[i]];
                if (i - iprev <= k) return true;
                m[nums[i]] = i;
            }
        }
        return false;
        
    }
};
