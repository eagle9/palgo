/*
Runtime: 56 ms, faster than 100.00% of Java online submissions for Range Sum Query - Mutable.
Memory Usage: 48.7 MB, less than 65.40% of Java online submissions for Range Sum Query - Mutable.

hua fenwick tree, shaun understood

*/
class NumArray {
    private FenwickTree tree;
    private int [] _nums;
    public NumArray(int[] nums) {
        _nums = nums;
        tree = new FenwickTree(nums.length);
        for (int i = 0; i < nums.length; i++) 
            tree.update(i+1, nums[i]); //0 is the dummy
    }
    
    public void update(int i, int val) {
        tree.update(i+1, val - _nums[i]);
        _nums[i] = val;
    }
    // 0 -- i-1 i
    // 0 ------  --   j
    public int sumRange(int i, int j) {
        return tree.query(j+1) - tree.query(i);
    }
}
class FenwickTree {
    int _sums [];
    public FenwickTree(int n) {
        _sums = new int[n + 1];
    }
    
    public void update(int i, int delta) {
        while (i < _sums.length) {
            _sums[i] += delta;
            i += i & -i;
        }
    }
    
    public int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += _sums[i];
            i -= i & -i;
        }
        return sum;
    }

}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
