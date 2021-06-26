//cutting idea is extended from largest rectangle in histogram, adapted from grandyang
//from row[0] to row[n-1], construct height, then use O(n) mono stack approach used in maximal rectangle in histogram
//runtime 20ms, faster than 94%, mem less than 61%
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int res = 0;
        if (matrix.empty()) return res;
        vector<int> height(matrix[0].size());
        for (int i = 0; i < matrix.size(); ++i) {
            //height.resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
    //solve largest rectangle in histogram
    int largestRectangleArea(vector<int>& height) {
        int res = 0;
        stack<int> s;
        height.push_back(0);
        for (int i = 0; i < height.size(); ) {
            //mono increase stack
            if (s.empty() || height[i] > height[s.top()]) s.push(i++);
            else {//height[i] <= top, trigger calculation to its left, lowest point
                int tmp = s.top(); s.pop();
                res = max(res, height[tmp] * (s.empty() ? i : (i - s.top() - 1)));
                //i stay its current value
            }
        }
        return res;
    }
};

