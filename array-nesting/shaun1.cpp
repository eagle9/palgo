//shaun first try, TLE after 1 bug fix
//add used set, accepted, runtime 48ms, faster than 16%, mem less than 9%
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        unordered_set<int> used;
        for (int start = 0; start < nums.size(); ++start) {
            if (used.count(start)) continue;
            unordered_set<int> temp;
            for (int j = start; ;) {
                if (j < nums.size() && !temp.count(nums[j])) {
                    temp.insert(nums[j]);
                    used.insert(nums[j]);
                    j= nums[j];
                }else break; //out of range or repeats
            }
            
            res = max(res, (int)temp.size()); //add (int) cast
        }
        return res;
        
    }
};
