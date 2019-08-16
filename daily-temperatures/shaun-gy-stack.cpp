//grandyang use of stack, runtime 184ms, faster than 98%, mem less than 38%
//shaun has read and understood, use of monotonic decreasing stack, pop when current element > stack.top, store index not value
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                auto t = st.top(); st.pop();
                res[t] = i - t;
            }
            //at this point, st.empty or ti <= st.top
            //monotonic decreasing stack
            st.push(i);
        }
        return res;
    }
};
