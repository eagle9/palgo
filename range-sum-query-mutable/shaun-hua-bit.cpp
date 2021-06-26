//shaun own code after reading huahua bit lecture
//binary index tree and its application to 307. range query sum mutable
// bug1 --- be clear about this:  array nums to sums, sums[i+1] stores nums[0] .. nums[i]
// bug2 -- nums_[i] = val
//runtime 32ms, faster than 90.41%, mem less than 44%
//cutting: thinking both prefix sum[i] stores sum of elements from 0 to i-1
//sum[0] = 0, sum[1] stores a[0], sum[2] stores a[0]+a[1]
//underlying array nums, init with all 0,  prefix sum index +1 of underlying array
//

class NumArray {
public:
    NumArray(vector<int>& nums) {
        //nums_ = vector<int>(nums.begin(), nums.end());
        int n = nums.size();
        nums_ = vector<int>(n,0); //init underlying array with 0 
        
        sum_ = vector<int>(n+1,0);
        for (int i = 0; i < n; ++i) {
            update(i, nums[i]); //nums_[i] impact prefix sum[i+1]
        }
    }
    
    //update nums_[i] with val, impacts prefix sum i+1 and above
    void update(int i, int val) { 
        int j = i+1;
        int delta = val - nums_[i];
        while (j < sum_.size()) {
            sum_[j] += delta;
            j += lowbit(j);
        }
        nums_[i] = val; 
    }
    
    //query prefix sum i, go to root >0
    int query(int i) {
        int ans = 0;
        //i from i to > 0, index 0 dummy node
        while (i > 0) {
            ans += sum_[i];
            i -= lowbit(i);
        }
        return ans;
    }
    
    int sumRange(int i, int j) { //elements from i to j
			//0 to j             0 to i-1
			//  i to j        
        return query(j+1) - query(i);
    }
private:
    vector<int> nums_; //underlying array
    vector<int> sum_; //prefix sum[i] stores sum of elements 0 to i-1
    int lowbit(int i) {
        return i & -i;
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

