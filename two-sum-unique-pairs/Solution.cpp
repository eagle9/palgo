class Solution {
public:
    /**
     * @param nums an array of integer
     * @param target an integer
     * @return an integer
     */
     //Your submission beats 83.20% Submissions!
     //jiadai c++

    int twoSum6(vector<int> &nums, int target) {
        // Write your code here
        if (nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        int count = 0;
        while (start < end) {
            if (nums[start] + nums[end] < target) {
                ++start;
            }
            else if (nums[start] + nums[end] > target) {
                --end;
            }
            else {
                ++count;
                ++start;
                --end;
                //remember nums is sorted now, start moving to >=
                // end moving to <=, we want unique, different number
                // the two following while loop is key to find unique pairs
                while (start < end && nums[start] == nums[start - 1]) {
                    ++start; //look for > number
                }
                
                while (start < end && nums[end] == nums[end + 1]) {
                    --end; //look for < number
                }
                
            }
        }
        
        return count;
    }
};
