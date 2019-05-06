//grandyang monotonic stack idea, read and understand, but how to figure out 
//not getting it yet
//runtime 16ms, faster than 84%, mem less than 24%
//time O(n), space O(n)
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> st;
        height.push_back(0); //run a test case, you will understand why you need this
        for (int i = 0; i < height.size();) {
            //push into stack if empty or greater than top
            if (st.empty() ||  height[i] > height[st.top()]) {
                st.push(i++);
            } else {
                //height[i] <= top
                int j = st.top(); st.pop();
                int h = height[j];
                int w = st.empty()? i: i - st.top() -1;
                //int w = st.empty()? i: i - j; ---> wrong answer
                res = max(res, h*w);
                
            }     
        }
        return res;
    }
};
