/*
huahua
Line 15: Char 18: runtime error: left shift of negative value -2147483648 (solution.cpp)
*/
class Solution1 {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int mask = 1;
        for (int i = 0; i < 32; ++i) {
            int count = 0;
            for (const int num : nums)
                if (num & mask) ++count;
            ans += (nums.size() - count) * count;
            mask <<= 1;
        }
        return ans;
    }
};

/*

grandyang
Runtime: 60 ms, faster than 96.67% of C++ online submissions for Total Hamming Distance.
Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Total Hamming Distance.
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int num : nums) {
                if (num & (1 << i)) ++cnt;
            }
            res += cnt * (n - cnt);
        }
        return res;
    }
};
