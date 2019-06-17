//lt using binary index tree, not quite understand
//from the problem , not easy to come up the idea to use binary index tree
// bit update and query index +- is not understood either
//to digest more
//runtime 244ms, faster than 74%, mem less than 61%
class Solution {
private:
    void update(vector<int>& BIT, int index, int delta){
        while (index > 0) {
            BIT[index] += delta;
            index -= index & (-index);
        }
    }

    int query(vector<int>& BIT, int index){
        int sum = 0;
        while (index < BIT.size()) {
            sum += BIT[index];
            index += index & (-index);
        }
        return sum;
    }
public:
    int reversePairs(vector<int>& nums){
        int n = nums.size();
        vector<int> nums_copy(nums);

        sort(nums_copy.begin(), nums_copy.end());

        vector<int> BITS(n + 1, 0);
        int count = 0;
        //i < j, nums[i] > 2*nums[i]
        for (int j = 0; j < n; j++) {
            // first i > 2*nums[j]
            int i = lower_bound(nums_copy.begin(), nums_copy.end(), 2LL * nums[j] + 1) - nums_copy.begin();
            count += query(BITS, i+1);
            
            //first i >= nums[j]
            i = lower_bound(nums_copy.begin(), nums_copy.end(), nums[j]) - nums_copy.begin();
            update(BITS, i+1 , 1);
        }
        return count;

    }
};
