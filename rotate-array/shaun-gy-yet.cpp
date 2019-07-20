/*
Could you do it in-place with O(1) extra space?
[1,2,3,4,5,6,7], k = 2
[6,7,1,2,3,4,5]
6 7  3 4 5 1 2
6 7  1 2 5 3 4 
shaun thought about swap
6 7  3  4  5  1 2
     1  2  5  3 4
           4  3 5
           3  4 5
     
*/
class Solution000 {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i) {
            int temp = nums[i+k];
            nums[i+k] = nums[i];
        }
    }
};
//naive use O(n) space, runtime 16ms, faster than 88%, mem less than 38%
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> t = nums;
        for (int i = 0; i < nums.size(); ++i) {
            nums[(i + k) % nums.size()] = t[i];
        }
    }
};
//runtime 28ms, faster than 88%, mem less than 96%
class Solution3 {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        nums.reserve(1+n);
        for (int i = 0; i < n - k; ++i) {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
    }
};

// grandyang, yet to understand
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int start = 0, idx = 0, pre = 0, cur = nums[0], n = nums.size();
        for (int i = 0; i < n; ++i) {
            pre = cur;
            idx = (idx + k) % n;
            cur = nums[idx];
            nums[idx] = pre;
            if (idx == start) {
                idx = ++start;
                cur = nums[idx];
            }
        }
    }
};
