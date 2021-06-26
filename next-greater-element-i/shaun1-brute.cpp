//shaun's original idea, accepted first sub
//runtime 20ms, faster than 16%, mem less than 17%
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m; //number to its index in nums2
        for (int i = 0; i < nums2.size(); ++i) {
            m[nums2[i]] = i;
        }
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            int i2 = m[nums1[i]]; //index in nums2 for x in nums1
            bool found = false;
            for (int j = i2+1; j < nums2.size();++j) { //find next greater
                if (nums2[j] > nums1[i]) {
                    res[i] = nums2[j];
                    found = true;
                    break;
                }
            }
            if (!found) res[i] = -1;
        }
        return res;
    }
};
