//sliding window, runtime 128ms, faster than 88%, mem less than 20%
//cutting, put all number into window product, expand right, contract left
//valid window, contribute to ans
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prod = 1, ans = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++];
            //window left ... right, product < k, left .. right, left+1 .. right, right
            //right - left + 1 products, all ending at right
            ans += right - left + 1;
        }
        return ans;
    }
};
