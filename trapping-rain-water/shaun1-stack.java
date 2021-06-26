//shaun use monotonic stack, first sub wrong answer
//draw example and figure out details
//only one line bug,   height[i] < st.top() ----> height[i] < height[st.top()]
//accepted after the fix, runtime 8ms, faster than 99%, mem less than 98%
/*
Runtime: 2 ms, faster than 24.18% of Java online submissions for Trapping Rain Water.
Memory Usage: 38.9 MB, less than 47.26% of Java online submissions for Trapping Rain Water.
*/
class Solution {
    public int trap(int[] height) {
        Stack<Integer> st = new Stack<>();
        int i = 0, res = 0;
        for (; i < height.length;) {
            //if (st.empty() || height[i] < st.top()) {
            if (st.isEmpty() || height[i] < height[st.peek()]) {
                st.push(i++);
            }else {
                // hi >= top
                int iBottom = st.pop();
                if (!st.isEmpty()) {
                    int iLeft = st.peek(); //st.pop();
                    int width = i - iLeft-1;
                    res += width * (Math.min(height[iLeft], height[i]) - height[iBottom]);
                }

            }
        }
        return res;
    }
}


