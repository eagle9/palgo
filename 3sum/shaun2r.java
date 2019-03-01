//shaun round 2, accepted with many fixes and consulting with good solution
//runtime 36ms, faster than 99.64%
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        
        int n  = nums.length; 
        for (int i = 0; i < n-2; i++) {
            //make sure no repeat use of first number, to prevent repeating triplets
            //use the example to figure this out, use second -1 as the first number will get a repeated triplet
            if  ( i > 0 && nums[i] == nums[i-1]) continue;
            int sum = 0 - nums[i];
            //find another two numbers after i that sum up to -nums[i]
            int left = i+1, right = n-1;
            while (left < right) {
                if (nums[left] + nums[right] == sum) {
                    res.add(Arrays.asList(nums[i], nums[left++], nums[right--]));
                    //left'  left    right   right'
                    //make sure nums[left] differs from nums[left']
                    while (nums[left] == nums[left-1] && left < right) left++;
                    //make sure nums[right] differs from nums[right']
                    while (nums[right] == nums[right+1] && left < right) right--;
                }else if (nums[left] + nums[right] < sum) {
                    left++; //look for larger number
                }else {  //left + right > sum
                    right--; //look for smaller number
                }
            }
        }
        return res;
    }
}
