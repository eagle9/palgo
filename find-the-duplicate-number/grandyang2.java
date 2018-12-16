//grandyang slow and fast two pointer
//beats 100%
//not quite understand
/*
Input: [1,3,4,2,2]
slow 1  3  2
fast 3  4  2
Output: 2
*/
class Solution {
    public int findDuplicate(int[] nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        while (true) {
            slow = nums[slow];
            t = nums[t];
            if (slow ==t) break;
        }
        return slow;
    }
}

/*
//grandyang idea, slow and fast two pointers, beats 100%
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        while (true) {
            slow = nums[slow];
            t = nums[t];
            if (slow == t) break;
        }
        return slow;
    }
};
*/
