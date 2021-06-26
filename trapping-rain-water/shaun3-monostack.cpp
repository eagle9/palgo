//shaun 3rd round try using mono stack
//runtime 4ms, faster than 96%, mem less than 5%
//bug 1 --- when ileft not available, no contribution 
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        height.push_back(0);
        int res = 0;
        
        for (int i = 0; i < height.size(); ) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            }else { //height[i] > st.top(), trigger computation
                int iBottom = st.top(); st.pop();
                if (!st.empty()) {
                    int iLeft = st.top();
                    int width = i - iLeft-1;
                    res += width * (min(height[i], height[iLeft]) - height[iBottom]);
                }
            }
        }
        
        return res;
    }
};

class Solution2 {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        height.push_back(0);
        int res = 0;
        
        for (int i = 0; i < height.size(); ) {
            if (st.empty() || height[i] <= height[st.top()]) {
                st.push(i++);
            }else { //height[i] > st.top(), trigger computation
                int iBottom = st.top(); st.pop();
                
                int iLeft = !st.empty()?st.top():0;
                int width = i - iLeft-1;
                res += width * (min(height[i], height[iLeft]) - height[iBottom]);
            }
        }
        
        return res;
    }
};
