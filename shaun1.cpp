/*

left 
  2 3 1  2  4  3
            l
  r r r  r  r  r 
s:2 5 6  8  10 9
         6  7  7
            6
l:1 2 3 (4)(4) (3)
           (3) (2)
left    0 1 2 3 4  5
right   0 1 2 3 4  5
sum     2 5 6 8 10 9
              6 7  7
                6  3
min_len 0     4  4 3
                 3 2
                 
                 shaun's own two pointer sliding window idea
accepted after 3 bug fixes
runtime 8ms faster than 97%, mem less than 100%
*/


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int left = 0, right = 0, n = nums.size();
        int sum = 0;
        int min_len = INT_MAX;
        while (right < n) {
            sum += nums[right++];
            while (sum >= s) {
                min_len = min(min_len, right-left); //right already ++,
                sum-= nums[left]; //- nums[left first]
                left++; //contract left
            }
        }
        //added INT_MAX check
        return min_len == INT_MAX? 0 :min_len;
    }
};
