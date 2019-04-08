/*
hua binary search

to understand and write yourself

Runtime: 12 ms, faster than 100.00% of C++ online submissions for Find K-th Smallest Pair Distance.
Memory Usage: 9.5 MB, less than 31.91% of C++ online submissions for Find K-th Smallest Pair Distance.



*/
class Solution1 {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums.back() - nums.front();
        while (l <= r) {
            int cnt = 0;
            int j = 0;
            int m = l + (r - l) / 2;
            for (int i = 0; i < n; ++i) {
                while (j < n && nums[j] - nums[i] <= m) ++j;
                cnt += j - i - 1;
            }
            cnt >= k ? r = m - 1 : l = m + 1;
        }        
        return l;
    }
};

//hua brute force with bucket sorting
//runtime 812ms, faster than 21%, mem less than 8%
class Solution2 {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const int N = nums.back();
        vector<int> count(N + 1, 0);        
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
               ++count[nums[j] - nums[i]]; //enumerate all pair distance
        
        //find bucket i,  sum count 0 to i >=k
        int sum = 0;
        for (int dist = 0; dist <= N; ++dist) {
            sum += count[dist];
            if (sum >= k) return dist;
        }
        return 0;
    }
};

//grandyang binary search, runtime 12ms, faster than 100%, mem less than 87%
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums.back() - nums.front();
        while (left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0; //cnt of pairs whose dist <= mid
            int start = 0; //smaller number index
            //two pointers to find cnt
            for (int i = 0; i < n; ++i) {
                while (start < n && nums[i] - nums[start] > mid) ++start;
                //now n_i- n_start <= mid
                cnt += i - start;
            }
            //pair count too small, increase limit
            if (cnt < k) left = mid + 1;
            //else cnt >= k
            else right = mid;
        }
        return left; //right okay too
    }
};
