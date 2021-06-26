/*
cutting: huahua bucket sort, O(n) time asked
track the min and max value of each bucket
first figure out the range of values in the array, then derive the bucket size

bin_size = range/n + 1, why not range/n???
index = (val - min)/bin_size
min bucket index = 0
max bucket index = n-1
    (max - min)/bin_size = range/ (range/n) = n, wrong
     range/(range/n+1)
     range could 0, at least 1 bin

runtime 4ms, faster than 99%, mem less than 80%

*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;
        
        const auto mm = minmax_element(nums.begin(), nums.end());
        const int range = *mm.second - *mm.first;
        //const int range = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
        const int bin_size = range / n + 1;
        vector<int> min_vals(n, INT_MAX); //min value in the bin
        vector<int> max_vals(n, INT_MIN); //max value in the bin
        for (const int num : nums) {
            const int index = (num - *mm.first) / bin_size;
            min_vals[index] = min(min_vals[index], num);
            max_vals[index] = max(max_vals[index], num);
        }
        
        int max_gap = 0;
        int prev_max = max_vals[0];
        //start from bin 1
        for (int i = 1; i < n; ++i) {
            //if bin's min and max available
            if (min_vals[i] != INT_MAX) {
                max_gap = max(max_gap, min_vals[i] - prev_max);
                prev_max = max_vals[i];
            }
        }
        return max_gap;
    }
};

