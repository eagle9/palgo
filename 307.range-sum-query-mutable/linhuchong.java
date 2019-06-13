/*
linhuchong java code, binary index tree,  runtime 83ms, faster than 56%
similar idea to grandyang

http://www.cnblogs.com/grandyang/p/4985506.html
tushar roy's youtube lecture explains well about this

*/
class NumArray {
    private int[] arr, bit;
    
    /**
     * @return: nothing
     */
    public NumArray(int[] nums) {
        arr = new int[nums.length];
        bit = new int[nums.length + 1]; //adding a dummy node
        
        for (int i = 0; i < nums.length; i++) {
            update(i, nums[i]);
        }
    }
    
    //update bi tree when arr of index is set to val
    //key is to understand update?????
    public void update(int index, int val) {
        int delta = val - arr[index];
        arr[index] = val;
        
        //from index+1 down to child
        for (int i = index + 1; i <= arr.length; i = i + lowbit(i)) {
            bit[i] += delta;
        }
    }
    
    //bi[index+1] stores the sum of arr from 0 to index
    //understood now
    public int getPrefixSum(int index) {
        int sum = 0;
        //index+1 to parent till dummy node
        //i = i - lowbit(i) --> flipping low 1 bit to get it parent
        
        for (int i = index + 1; i > 0; i = i - lowbit(i)) {
            sum += bit[i];
        }
        //bi tree property: from index+1 to root, sum of node value is the prefix sum
        return sum;
    }
    
    //math to get low set bit
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
