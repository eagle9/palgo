//brute fore for i <j < k, find the max 
//no idea except brute force
/*
grandyand analysis cases, sorted, all negatives, all positives, same, the top3 numbers
negative  and positive 3 numbers, 1 neg, need the 2 smallest positives, so they consecutive
1 neg and 2 positive, min abs neg == last negative,  first 2 positives, 
2 negative and 1 positive, first 2 negatives, 1 last positive, yields max product3

runtime 68ms, faster than 59%, mem less than 21% 
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() < 3) return INT_MIN;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // first 2 negative  and last >=0
        int p = nums[0] * nums[1] * nums[n - 1];
        // last negative and first 2 >=0
        //all 3 negative, or all 3 positive, last 3
        return max(p, nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};
