//grandyang monotonic increase stack idea, store index, trigger calculation when current height <= top,  read and understand
//use an example to figure out the details:
//
//  4
// 3 
//2  2
//     
//     0
// stack: 2 3 4, i=3, h[3] = 2 < top=4
// 4*1, 3*(3-1-0) = 6, 2*3=6
// stack: empty
// stack: 2, 0 comming at i = 4, < top=2
// 2*4 = 8
// so max is 8
//
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
            //push into stack if empty or greater than top, mono increase stack
			//stack store index
            if (st.empty() || height[st.top()] < height[i]) {
                st.push(i++);
            } else {
                // height[i] <= st.top 
                int j = st.top(); st.pop();
                int h = height[j];
				//           
				// [ h[?] / h[j] ] 
				//                <= h[i]
				//                not clear about w
                int w = st.empty()? i: i - 1 - st.top();
                //int w = st.empty()? i: i - j; ---> wrong answer
                res = max(res, h*w);
                
            }     
        }
        return res;
    }
};
