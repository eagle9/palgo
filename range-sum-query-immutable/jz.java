//jz beats 63.00%
class NumArray {

    private int[] prefix;
    
    public NumArray(int[] nums) {
        prefix = new int[nums.length + 1];
        getPrefix(nums, prefix);
    }
    
    //find sum from i to j
    
    public int sumRange(int i, int j) {
        return prefix[j + 1] - prefix[i];
        // nums[j]             nums[i-1]
    }
    
    //prefix[i] stores the sum from 0 to i-1
    //0 --- 0
    //1 -- nums[0]
    //2 -  nums[0] + nums[1]
    private void getPrefix(int[] nums, int[] prefix) {
        for (int i = 0; i < nums.length; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
