// hua 2d dp hint
//cutting angle:  sum value is very small, so we can look at with i numbers, and think about all possible sum
//values that we can make. it is not hard to figure out sum's value range, it is key to use offset to make the values non-negative, to set up DP easily

//this DP is kind of special that the 2nd dimemsion j does not have order, only first dimension i has good order from low to high, the 2d table will have many cells not populated 

// runtime 20ms, faster than 77%, mem less than 33%
class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int n = nums.size();
        const int sum = std::accumulate(nums.begin(), nums.end(), 0); //accumulate with init=0
        if (sum < S) return 0;
        const int offset = sum; //use offset to make sum value non-negative
        
        // ways[i][j] means total ways to sum up to (j - offset) using i elements from 0.
        //i is len of the number array, j is the sum value + offset
        vector<vector<int>> ways(n + 1, vector<int>(sum + offset + 1, 0));
        ways[0][offset] = 1;
        for (int i = 0; i < n; ++i) {
            // j - nums[i] >= 0, j+nums[i] <= 2*sum 
            // j >= nums[i], j <= 2*sum - nums[i] to ensure j index in bound
            for (int j = nums[i]; j <= 2 * sum - nums[i]; ++j)
            if (ways[i][j]) {
                ways[i + 1][j + nums[i]] += ways[i][j];
                ways[i + 1][j - nums[i]] += ways[i][j];
            }        
        }
      
        //return ways.back()[S + offset];
        return ways[n][S+offset];
    }
};

//hua using rolling array, since dp[i] depends only on dp[i-1]
//shaun modified to align better with above
//runtime 16ms, faster than 79%, mem less that 37%
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
      const int n = nums.size();
      const int sum = std::accumulate(nums.begin(), nums.end(), 0);
      if (sum < std::abs(S)) return 0;
      const int kOffset = sum;
      const int kMaxN = sum * 2;
      vector<int> ways(kMaxN+1, 0);      
      ways[kOffset] = 1; //sum value = 0, when 0 numbers considered
      for (int num : nums) {
        vector<int> tmp(kMaxN+1, 0);//new row
        
        /*for (int i = 0; i <= kMaxN; ++i) {    
          if (i + num <= kMaxN) tmp[i] += ways[i + num];
          if (i - num >= 0)    tmp[i] += ways[i - num];
            
        }*/
        
          /*   bug, wrong answer
        for (int i = num; i <= kMaxN - num; ++i) {
            tmp[i] = ways[i+num];  //sum i+num - num = i
            tmp[i] = ways[i-num];   //get i from sum value i-num + num
        }*/
         for (int j = num; j <= kMaxN - num; ++j) {
             if (ways[j]) {
                tmp[j+num] += ways[j];  
                tmp[j-num] += ways[j];   
             }
        }
        std::swap(ways, tmp);
      }
      return ways[S + kOffset];
    }
};
