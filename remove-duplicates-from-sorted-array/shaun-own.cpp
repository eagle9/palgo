/*
a loop from 0 to len -1
  inside loop while nums[i] = nums[i-1], skip it
  
  use storeIndex to store unique elements

testing:
[0,0,1,1,1,2,2,3,3,4],

storeIndex
0           0
1           1
2           2
3           3

shaun own idea and code, accepted after 2 bug fixes
these 2 bugs are the similar missing thought,  i < len boundary check
runtime 16ms, faster than 99%, mem less than 74%
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(), storeIndex = 0; //store unique elements
        for (int i = 0; i < len; ++i) {
            //bug 1, should add i < len right bound check
            while (i>=1 && i< len && nums[i] == nums[i-1]) i++; //skip repeated elements
            //now nums[i] is unique and store it
            if (i < len) // bug 2, should check i < len after while loop
                nums[storeIndex++] = nums[i];
        }
        return storeIndex;
    }
};
