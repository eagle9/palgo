//grandyang dp and binary search idea, edward similar idea
//how to come up this idea and why it is correct? 
//the idea is not hard to implement though
//runtime 0ms, faster than 100%, mem less than 8%
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> ends{nums[0]};
        for (auto a : nums) {
            if (a < ends[0]) ends[0] = a;
            else if (a > ends.back()) ends.push_back(a);
            else {
                //find first index in ends that >= a
                int left = 0, right = ends.size()-1;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (ends[mid] >= a) right = mid; //func true push to left
                    else left = mid + 1;
                    
                }
                ends[left] = a;
                //ends[right] = a; //okay  too
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
