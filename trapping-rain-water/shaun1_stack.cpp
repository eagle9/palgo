//shaun use monotonic stack, first sub wrong answer
//draw example and figure out details
//only one line bug,   height[i] < st.top() ----> height[i] < height[st.top()]
//accepted after the fix, runtime 8ms, faster than 99%, mem less than 98%
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i = 0, res = 0;
        for (; i < height.size();) {
            //if (st.empty() || height[i] < st.top()) {
            if (st.empty() || height[i] < height[st.top()]) {
                st.push(i++);
            }else {
                // hi >= top
                int iBottom = st.top(); st.pop();
                if (!st.empty()) {
                    int iLeft = st.top(); //st.pop();
                    int width = i - iLeft-1;
                    res += width * (min(height[iLeft], height[i]) - height[iBottom]);
                }
                
            }
        }
        return res;
    }
};
