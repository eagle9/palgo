class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        long maxArea = 0;
        int i = 0;
        while (i < heights.size()) {
            if (st.empty() || heights[i] >= st.top()) st.push(i++);
            else {
                //heights[i] < st.top
                int temp = st.top(); st.pop();
                int w = st.empty()? i: i - st.top()-1;
                long area = heights[temp]*w;
                maxArea = max(area, maxArea);
            }
        }
        while (!st.empty()) {
            int temp = st.top(); st.pop();
            long w = st.empty()? i: i - st.top()-1;
            long area = heights[temp]*w;
            maxArea = max(area, maxArea);
        }
        return (int)maxArea;
    }
};
