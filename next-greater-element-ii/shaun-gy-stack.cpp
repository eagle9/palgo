/*
input: 1 3 4  2 
output:3 4 -1 3

1 3 4 2 1 3
*/
//shaun's naive stack try, wrong answer, why? 
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        
        unordered_map<int,int> m;
        
        for (int i =0 ; i < 2*n; ++i) {
            int num = nums[i % n];
            while (!st.empty() && st.top() < num) {
                m[st.top()] = num;
                st.pop();
            }
            if (i < n)
                st.push(num);
        }
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            if (m.count(nums[i]))
                res[i] = m[ nums[i]]; 
        }
        return res;
    }
};

//grandyang code, runtime 84ms, faster than 94%, mem less than 83%
class Solution2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i =0 ; i < 2*n; ++i) {
            int num = nums[i % n];
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num;
                st.pop();
            }
            if (i < n)
                st.push(i);
        }
        return res;
    }
};
