//grandyang use of bit and sorting
//understand some , compare to hua's <<count of smaller numbers after self>>
// how about rank1???
//runtime 252, faster than 70%, mem less than 53%
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums);
       
        sort(sorted.begin(), sorted.end());
        
        vector<int> bit(n + 1);
        
        unordered_map<int, int> m; //store number to its sorted index
        //for (int i = 0; i < n; ++i) m[v[i]] = i + 1;
        
        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            // i < j, but nums[i] > 2*nums[j]
            //find first nums[i] >= nums[j]/2.0
            
            int rank1 = lower_bound(sorted.begin(), sorted.end(), nums[i] / 2.0) - sorted.begin();
            res += query(rank1, bit);
            
            int rank2 = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin()+1;
            update(rank2, bit);
        }
        return res;
    }
    int query(int i, vector<int>& bit) {
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
