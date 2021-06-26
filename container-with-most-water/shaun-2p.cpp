//shaun upon 2pointer hint by hua/grandy etc. 
//cutting, started with widest container, then squeeze from left or right, keep higher edge at the moment, natural use of 2pointer template

//runtime 20ms, faster than 80%, mem less than 73%
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, left = 0, right = height.size()-1;
        while (left < right) {
            int area = min(height[left], height[right])* (right-left);
            if (area > res) res = area;
            
            if (height[left] < height[right]) {
                left++; //keep right edge since it is higher
            }else {
                right--; //keep left edge since it is higher
            }
        }
        return res;
            
    }
};
