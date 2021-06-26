//jiadai c++-> java, Your submission beats 80.40% Submissions!
public class Solution {
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(int [] nums, int target) {
        Integer result = null;
        if (nums.length < 3) 
            return result;
        Arrays.sort(nums);
        int closestSum = nums[0] + nums[1] + nums[2]; //use this var to track the closest
        for (int i = 0; i < nums.length - 2; ++i) { //choose first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int twoSum = target - nums[i];
            int start = i + 1, end = nums.length -1;
            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum == twoSum) {
                    return target;
                }
                else if (sum < twoSum) {
                    ++start;
                }
                else {
                    --end;
                }
                
                //abs(nums[i] + sum - target) = abs(twoSum - sum)
                if (Math.abs(twoSum - sum) < Math.abs(closestSum - target)) {
                    closestSum = sum + nums[i];
                }
            }
        }

        return closestSum;
    }
}
