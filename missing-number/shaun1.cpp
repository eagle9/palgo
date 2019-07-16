//shaun's own idea, similar to lt idea4, using gauss formula
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

//lt bit manipulation idea,accumulate i^nums[i].  shaun coded from the idea
//not easy to come up the idea
//draw a picture of xor reduction
// index: 0 1 2  (3) 
//        3 0 1
// index: from 0 to n-1 n        
//   nums:1     n-1 n, consider index and nums, all numbers are paired except the missing number
//   so ^ all or XOR all numbers and index from 0 to n will get the missing number
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
