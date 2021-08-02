class Solution {
    public int longestOnes(int[] nums, int k) {
        int [] A = nums;
        int n = A.length;
        int left = 0;
        int cnt = 0; //number of 0 in the window
        int res = 0;
        for (int right = 0; right < n; ++right) {
            //expand to right
            if (A[right] == 0) ++cnt;
            //shrink left
            while (cnt > k) {
                if (A[left] == 0) --cnt;
                ++left;
            }
            //cnk == k and left to right
            res = Math.max(res, right - left + 1);
        }
        return res;
    }
}
