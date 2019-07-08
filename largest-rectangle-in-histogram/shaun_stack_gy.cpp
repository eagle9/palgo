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
		//make sure the stack will be empty after the height loop
        for (int i = 0; i < height.size();) {
            //push into stack if empty or greater than top
            if (st.empty() || height[st.top()] < height[i]) {
                st.push(i++);
            } else {
                //top >= height[i] 
                int j = st.top(); st.pop();
                int h = height[j];
				//           
				// [ h[?] / h[j] ] 
				//                h[i]
                int w = st.empty()? i: i - 1 - st.top();
                //int w = st.empty()? i: i - j; ---> wrong answer
                res = max(res, h*w);
                
            }     
        }
        return res;
    }
};
