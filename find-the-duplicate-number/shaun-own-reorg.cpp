/*
Input: [1,3,4,2,2]
Output: 2
1  3  4  2  2
1  4  3  2  2
1  2  3  4  2 
      ^ ---- 2 != 
      
shaun's own idea to store the val to index=val-1
accepted after first try, proof reading with examples
runtime 8ms, faster than 98%, mem less than 51%
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(); 
        //number range 1 to n-1
        //only 1 duplicate number and find it
        for (int i = 0; i < n; ) {
            int val = nums[i];
            //store val at val-1
            if (i != val - 1) {
                if (nums[i] == nums[val-1]) return nums[i];
                swap(nums[i], nums[val-1]);
            }else {
                i++;
            }
            
        }
        return -1;
    }
};


