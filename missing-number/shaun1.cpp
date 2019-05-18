//shaun's own idea, similar to lt idea4
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 1; i <= n; ++i) sum += i;
        
        int sum1 = 0;
        for (int x: nums) sum1+=x;
        return sum - sum1;
    }
};

//lt bit manipulation idea, shaun coded from the idea
//draw a picture of xor reduction
// index: 0 1 2  (3) 
//        3 0 1
//accepted first sub
//runtime 24ms, faster than 96%, mem less than 10%
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for (int i = 0; i < n; ++i) {
            res ^= i ^ nums[i];
        }
        return res;
    }
    
};
