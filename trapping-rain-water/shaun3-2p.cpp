//shaun 3rd try, 2 bugs, bug 1 temp/diff should be > 0
//bug 2 --- max1 to track max
//runtime 4ms, faster than 96%, mem less than 92%
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n); //max go left from i
        vector<int> maxRight(n); //max go right from i
        int max1 = 0;
        for (int i = 0; i < n; ++i) {
            maxLeft[i] = max1;
            max1 = max(max1, height[i]);
        }
        
        max1 = 0;
        for (int i = n-1; i >= 0; --i) {
            maxRight[i] = max1;
            max1 = max(max1, height[i]); 
        }
        
        int water = 0;
        for (int i = 0; i < n; ++i) {
            int temp = min(maxLeft[i], maxRight[i]) - height[i];
            if (temp > 0)
                water += temp;
        }
        return water;
    }
};

