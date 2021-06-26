//shaun coded from gy's binary search idea
//cutting: we search the minized sum, try search the minimized sum in the range of [left,right]
//split the array such that each group/partition sum <= the value
// the larger the value, it is easier to split, once we can split, we reduced the range, right = mid
// if we can not split, the value is too small, so left = mid+1
//squeeze this way till left == right
// return left
//runtime 0ms, faster than 100%, mem less than 100%
class Solution {
public:
    //non-negative integer array split into m groups, each group has a sum, minimize the sum, return the minimized sum
    //nums elements 0 to n-1, n groups, the minimized sum is max_elements
    //1 group, the sum is the accumulate(nums.begin(), nums.end(), 0L)
    int splitArray(vector<int>& nums, int m) {
        long left = *max_element(nums.begin(), nums.end());
        long right = accumulate(nums.begin(), nums.end(), 0L); // bug 0 --> 0L
        while (left < right) {
            long mid = left + (right-left)/2;
            if (can_split(nums, m, mid)) right = mid;
            else left = mid+1;
        }
        //left == right now
        return (int)left;
    }
    
    //split nums into m groups, each group sum <= max_sum
    bool can_split(vector<int>& nums, int m, long max_sum) {
        long cur_sum = 0;
        int count  = 1; //bug 2: 0 ---> 1, why?  use an example   [7 2 5 10 8], max_sum = 18
        for (int num: nums) {
            if (cur_sum + num > max_sum) {
                count++;
                if (count > m) return false;
                cur_sum = num; //reset
            }else {
                cur_sum += num;
            }
        }
        return count <= m;
    }
};
/*
7 2 5 10 8, m = 2
left = 10, right = 32
mid = 21
7 2 5, 10 8, can_split return true
left = 10, right = 21
mid = 15
7 2 5, 10, 8, can_split return false
left = 16, right = 21
mid = 37/2 = 18
7 2 5, 10 8, can_split return true
left = 16, right = 18
mid = 17
7 2 5, 10, 8, can_split return false
left = 18, right = 18
return 18, done



*/
