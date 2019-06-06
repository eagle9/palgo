//idea forming, assumption always exists and non empty array
//grandyang bit manipulation idea
//figure out the majority element bit by bit, shaun got the idea and coded
//accepted first sub
//runtime 24ms, faster than 61%, mem less than 85%
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i  = 0; i < 32; ++i) {
            
            int ones = 0, zeroes = 0; //count of 0/1 at ith bit of each number
            for (int x: nums) {
                if ((x >>  i) &1 == 1) ones++;
                else zeroes++;
                if (ones > n/2 || zeroes > n/2) break;
            }
            
            if (ones > n/2) { //ith digit is 1
                res += (1 << i);
            }
        }
        return res;
        
    }
};
