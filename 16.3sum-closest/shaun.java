//shaun first try, wrong answer
class Solution1 {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        
        int minDiff = Integer.MAX_VALUE;
        int res = 0;
        for (int i = 0; i < n-2; i++) {
            int left = i+1, right = n-1;
            boolean flag = true;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = Math.abs( sum- target);
                if (diff < minDiff) {
                    minDiff = diff;
                    res = sum;
                }
                if (flag) {
                    left++;
                    flag = false;
                }else {
                    right--;
                    flag = true;
                }
            }
        }
        return res;
    }
}
/*shaun's 2nd try, brute force, accepted
Runtime: 69 ms, faster than 8.28% of Java online submissions for 3Sum Closest.
Memory Usage: 40 MB, less than 8.84% of Java online submissions for 3Sum Closest.
*/
class Solution2 {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        
        int minDiff = Integer.MAX_VALUE;
        int res = 0;
        for (int i = 0; i < n-2; i++) {
            for (int j = i+1; j < n-1; j++) {
                for (int k = j+1; k < n; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    int diff = Math.abs( sum- target);
                    if (diff < minDiff) {
                        minDiff = diff;
                        res = sum;
                    }
                }
            }
        }
        return res;
    }
}

/*shaun's 3rd try, not give up on first try, from flag to sum< target condition
immediately accepted: 
Runtime: 9 ms, faster than 96.47% of Java online submissions for 3Sum Closest.
Memory Usage: 38 MB, less than 41.42% of Java online submissions for 3Sum Closest.

my first try is so close, do some testing, maybe ask for hint or help

*/
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        
        int minDiff = Integer.MAX_VALUE;
        int res = 0;
        for (int i = 0; i < n-2; i++) {
            int left = i+1, right = n-1;
            boolean flag = true;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = Math.abs( sum- target);
                if (diff < minDiff) {
                    minDiff = diff;
                    res = sum;
                }
                if (sum < target) left++; //key 
                else right--;
            }
        }
        return res;
    }
}
