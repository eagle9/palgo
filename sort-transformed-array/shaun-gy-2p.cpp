/*
gy two pointer idea with math guide
runtime 8ms, faster than 70%, mem less than 100%

*/
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size(), i = 0, j = n - 1;
        vector<int> res(n);
        int idx = a >= 0 ? n - 1 : 0;
        while (i <= j) {
            int x = cal(nums[i], a, b, c), y = cal(nums[j], a, b, c);
            if (a >= 0) { //idx from n-1
                if (x >= y) {
                    res[idx--] = x; i++;
                }else {
                    res[idx--] = y; j--;
                }
            } else { //a < 0, idx from 0
                if (x >= y) {
                    res[idx++] = y; j--;
                }else {
                    res[idx++] = x; i++;
                }
                
            }
        }
        return res;
    }
    int cal(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
}; 
