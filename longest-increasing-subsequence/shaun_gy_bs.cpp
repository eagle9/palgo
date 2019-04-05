//shaun modified grandyang's binary search idea
//runtime 4ms, faster than 100%, mem less than 54%
//why this idea work???
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> ends {nums[0]};
        for (auto a : nums) {
            //smaller than head, replace the head
            if (a < ends[0]) ends[0] = a;
            //greater than tail, append to tail
            else if (a > ends.back()) ends.push_back(a);
            else {
                //in between ends head and tail, find its pos in ends, replace
                //find first >= a
                int left = 0, right = ends.size()-1;
                while (left + 1 < right) {
                    int mid = left + (right - left) / 2;
                    // mid a right
                    if (ends[mid] < a) left = mid + 1;
                    // left a<= mid, == squeeze to left
                    else  right = mid;
                }
                if (ends[left] >= a) ends[left] = a;
                else ends[right] = a;
            }
        }
        return ends.size();
    }
};

//grandyang binary search using lower_bound
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (auto a : nums) {
            auto it = lower_bound(v.begin(), v.end(), a);
            if (it == v.end()) v.push_back(a);
            else *it = a;
        }
        return v.size();
    }
};

//grandyang binary search using upper_bound
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (auto a : nums) {
            if (find(v.begin(), v.end(), a) != v.end()) continue;
            auto it = upper_bound(v.begin(), v.end(), a);
            if (it == v.end()) v.push_back(a);
            else *it = a;
        }
        return v.size();
    }
};
