/*
linhuchong java code, binary index tree,  runtime 103ms, faster than 99%
similar idea to grandyang
grandyang c++ does not work

http://www.cnblogs.com/grandyang/p/4985506.html

*/
class NumArray {
    private int[] arr, bit;
    
    /**
     * @return: nothing
     */
    public NumArray(int[] nums) {
        arr = new int[nums.length];
        bit = new int[nums.length + 1];
        
        for (int i = 0; i < nums.length; i++) {
            update(i, nums[i]);
        }
    }
    
    public void update(int index, int val) {
        int delta = val - arr[index];
        arr[index] = val;
        
        for (int i = index + 1; i <= arr.length; i = i + lowbit(i)) {
            bit[i] += delta;
        }
    }
    
    public int getPrefixSum(int index) {
        int sum = 0;
        for (int i = index + 1; i > 0; i = i - lowbit(i)) {
            sum += bit[i];
        }
        return sum;
    }
    
    private int lowbit(int x) {
        return x & (-x);
    }

    public int sumRange(int left, int right) {
        return getPrefixSum(right) - getPrefixSum(left - 1);
    }
}
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
