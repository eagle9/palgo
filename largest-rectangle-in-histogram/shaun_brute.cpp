#include <vector>
#include <iostream>
using namespace std;
//shaun's brute force idea, TLE
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int minHeight = INT_MAX; //min height from i 
            for (int j = i; j < n; ++j) {
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, (j-i+1) * minHeight);
            }
        }
        return maxArea;
    }
};
int main() {
    vector<int> h = {2,1,5,6,2,3};
    int res = Solution().largestRectangleArea(h);
    cout << "res = " << res << endl;
}
//not quite come up the solution idea even with hint of stack

