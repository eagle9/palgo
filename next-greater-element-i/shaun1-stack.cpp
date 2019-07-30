//shaun's original idea, naive,  accepted first sub
//
//runtime 20ms, faster than 16%, mem less than 17%
/*
    unique numbers in both array, 1 is a subset of 2
    output next greater of 1
    focus on nums2, hash: number to its next greater, for each i, then from j= i+1 to end, if nums2[j] > nums2[i],  nums2[i] --> nums2[j]
    time O(n^2)
    why stack? --- O(n)
    // 1 3 4 2 ---- 1 3 4, monotonic stack
*/
class Solution1 {
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


//shaun upon hint of using stack to get next greater element
//runtime 8ms, faster than 99%, mem less than 12%
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m; //in nums2, number to its next greater 
        
        
        stack<int> st;
        for (int i = 0; i < nums2.size(); ++i) {
            if (st.empty() || nums2[i] < st.top()) st.push(nums2[i]);
            else {
                //nums2[i] > st.top()
                while (!st.empty() && nums2[i] > st.top()) {
                    int small = st.top(); st.pop();
                    m[small] = nums2[i];
                }
                st.push(nums2[i]);
            }
        }
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i) {
            if (m.count(nums1[i])) res[i] = m[nums1[i]];
        }
        return res;
    }
};

