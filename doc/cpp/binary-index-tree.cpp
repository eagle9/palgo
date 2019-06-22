//shaun own code after reading huahua bit lecture
//binary index tree and its application to 307. range query sum mutable
// bug1 --- be clear about this:  array nums to sums, sums[i+1] stores nums[0] .. nums[i]
// bug2 -- nums_[i] = val
//runtime 36ms, faster than 90.41%, mem less than 44%
class BIT {
public:
    void init(int n){
        sum = vector<int>(n+1,0);
        //sum[0]  = 0;
        //sum[1] = a[0]
    }
	//update i += lowbit(i), why? , just remember update first, query second, 
	//update from from left to right +=, query right to left -=
    void update(int i, int delta) {
        //i from 1 to sum.size()
        while (i < sum.size()) { //i < n+1, last i = n
            sum[i] += delta;
            i += lowbit(i);
        }
    }
	//query i -= lowbit(i), why? 
    int query(int i) {
        int ans = 0;
        //i from i to > 0, index 0 dummy node
        while (i > 0) {
            ans += sum[i];
            i -= lowbit(i);
        }
        return ans;
    }

private:
    vector<int> sum; //store prefix sum from 1 to i
    int lowbit(int i) {
        return i & -i;
    }
};
class NumArray {
public:
    NumArray(vector<int>& nums) {
        nums_ = vector<int>(nums.begin(), nums.end());
        int n = nums_.size();
        tree_.init(n);
        int i = 1;
        for (int i = 0; i < n; ++i) {
            tree_.update(i+1, nums_[i]);
            
        }
    }
    
    void update(int i, int val) {
        tree_.update(i+1, val-nums_[i]);
        nums_[i] = val; //bug 2, don't miss this, keep nums_ sync'ed with nums
    }
    
    int sumRange(int i, int j) {
        return tree_.query(j+1) - tree_.query(i);
    }
private:
    BIT tree_;
    vector<int> nums_;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
