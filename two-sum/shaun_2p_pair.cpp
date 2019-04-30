//use sorting, two pointers and pair, runtime 8ms, faster than 100%, mem less than 58%
//use pair to remember original position
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> vp(n);
        
        for (int i = 0; i < n; ++i) {
            vp[i] = make_pair(nums[i],i);
        }
        sort(vp.begin(), vp.end());
        
        vector<int> res(2);
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = vp[left].first + vp[right].first;
            if ( sum == target) {
               res[0] = vp[left].second;
               res[1] = vp[right].second;
               return res;
            }else if (sum < target) {
                ++left;
            }else {
                --right;
            }
        }
        return res;
    }
};
