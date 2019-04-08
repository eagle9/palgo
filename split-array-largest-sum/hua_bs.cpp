// hua binary search, runtime 4ms, faster than 100%, mem less than 100%
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long left = *max_element(nums.begin(), nums.end());
        long right = accumulate(begin(nums), end(nums), 0L) + 1;
        while (left < right) {
            long limit = (right - left) / 2 + left;
            if (min_groups(nums, limit) > m)  //group count > m, limit too small
                left = limit + 1;
            else // groups <= m
                right = limit;
        }
        //left == right  <=m
        return right;
    }
private:
    //split nums, one group sum <= limit, return # of groups
    int min_groups(const vector<int>& nums, long limit) {
        long sum = 0;
        int groups = 1; 
        //why start from 1? imagine 1 number, limit very large
        // > limit wont enter, return 1 group
        for (int num : nums) {
            if (sum + num > limit) {
                sum = num; //reset 
                ++groups; //increment group count
            } else {
                sum += num;
            }
        }    
        return groups;
    }
};
