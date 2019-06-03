//shaun's code with bst as sliding window
//accepted first sub, 
//runtime 16ms, faster than 93%, mem less than 18%
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> tree;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = tree.lower_bound(nums[i]);  //first >= ni
            if (it!= tree.end() && (long)*it - (long)nums[i] <= t) return true;
            
            it = tree.upper_bound(nums[i]); //first > ni
            if (it!= tree.begin()) { //if begin(), you can not --
                it--; // < ni, but max
                if ((long)nums[i] - (long)*it <= t) return true;
            }
            tree.insert(nums[i]);
            if (tree.size() > k) {
                //remove oldest element
                tree.erase(nums[i-k]);
            }
        }
        return false;
    }
};
