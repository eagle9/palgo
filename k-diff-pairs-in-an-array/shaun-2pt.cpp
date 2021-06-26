//grandyang two pointers, shaun init with left and right, does not work
//for each start, loop from the 
//runtime 448ms, faster than 8%, mem less than 92%
//not easy to get right, have to do a lot of testing before you okay to officer
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        int count = 0; 
        sort(nums.begin(), nums.end());
        // Pick all elements one by one 
        for (int i = 0; i < n; i++) {  
            // See if there is a pair of this picked element 
            for (int j = i+1; j < n; j++) {
                if (nums[j] - nums[i] == k ) {
                    count++; 
                    //break, no more j will be checked to avoid duplicates
                    break;
                }
            }
            //starting point unique,
            while (i+1 < n && nums[i] == nums[i+1]) i++;
        } 
        return count; 
    }
};
