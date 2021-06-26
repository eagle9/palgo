//grandyang idea bit manipulation
//beats 7%, not as fast as we imagine as a O(n) algorithm
class Solution {
    public int findDuplicate(int[] nums) {
        
        int res = 0, n = nums.length;
        for (int i = 0; i < 32; ++i) {
            int bit = (1 << i), cnt1 = 0, cnt2 = 0;
            for (int k = 0; k < n; ++k) {
                if ((k & bit) > 0) ++cnt1;
                if ((nums[k] & bit) > 0) ++cnt2;
            }
            if (cnt2 > cnt1) res += bit;
        }
        return res;
    
    }
}

