/*
int n = nums.size()
range 1 to n
disappeared numbers 
O1 space and O(n) time
tried to sum all, can figure out with the sum value, does not work
change cutting angle

not idea after 7month
grandyang hint,   the officer wants you to get this observation

value range 1 to n, index 0 to n-1
reorgazie the number by its value, use the input array 
[4,3,2,7,8,2,3,1]
 7     4
 3           7
 2   3
 3 2    ---- 3 should go to 3, but already there
 3 2 3 4 (8)
          1    7  8
 1 2 3  4 3 (2) 
 3 4 8 2 7 1
 1 2 3 4 3 2 7 8
 after reorg, if nums[i] != i+1, then i+1 disappeared
 
 accepted first sub after working out with an example
 feeling great after a slight hint generated clever idea
 great implementation without bug!!! give myself thumbs up!!
 runtime 116ms, faster than 89%, mem less than 94%
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        //reorg by value
        int i  = 0; 
        while (i < n) {
            int value = nums[i];
            //value to nums[value-1]
            if (value != i+1) {
                if (nums[i] != nums[value-1])
                    swap(nums[i], nums[value-1]);
                else 
                    i++;
            }else {
                i++;
            }
        }
        
        for (int i = 0; i < n; ++i ) {
            if (i+1 != nums[i]) res.push_back(i+1);
        }
        return res;
    }
};
