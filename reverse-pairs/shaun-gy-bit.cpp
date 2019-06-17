//grandyang use of bit and sorting
//not understand, read more, have to move on 
//runtime 252, faster than 70%, mem less than 53%
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> v = nums, bit(n + 1);
        sort(v.begin(), v.end());
        unordered_map<int, int> m; //store number to its sorted index
        for (int i = 0; i < n; ++i) m[v[i]] = i + 1;
        
        for (int j = n - 1; j >= 0; --j) {
            // i < j, but nums[i] > 2*nums[j]
            //first nums[i] >= nums[j]/2.0
            
            int i = lower_bound(v.begin(), v.end(), nums[j] / 2.0) - v.begin();
            res += getSum(i, bit);
            update(m[nums[j]], bit);
        }
        return res;
    }
    int getSum(int i, vector<int>& bit) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    void update(int i, vector<int>& bit) {
        while (i < bit.size()) {
            bit[i] += 1;
            i += (i & -i);
        }
    }
};
