//jiadai c++, 82%
//jiadai java Your submission beats 64.40% Submissions!
public class Solution {
    /*
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    //use ArrayList<> as parameter is faster than use List<>
    public List<Integer> previousPermuation(ArrayList<Integer> nums) {
        
        int n = nums.size();
        if (n == 0 || n == 1) {
            return nums;
        }

        int i = n - 2;
        //from tail, find nums[i] that jumps >
        while (i >= 0 && nums.get(i) <= nums.get(i+1)) {
            --i;
        }

        if (i >= 0) {
            int j = n - 1;
            while (j > i && nums.get(j) >= nums.get(i)) {
                --j;
            }
            //swap i j
            Integer temp = nums.get(i);
            nums.set(i, nums.get(j));
            nums.set(j,temp);
        }
        //reverse(nums.begin() + i + 1, nums.end());
        i = i+1;
        int j = n-1;
        while (i < j) {
            //swap list
            Integer temp = nums.get(i);
            nums.set(i, nums.get(j));
            nums.set(j,temp);
            i++;
            j--;
        }
        return nums;
    }
}
