//shaun's own code, two pointer idea, beats 100%
class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        if (nums.empty()) return {};
        int n = nums.size();
        //0 -- k-1 ...n-1 ==> n-k +1
        int rlen = n - k + 1; //number of sums/windows
        
        vector<int> res(rlen);
        int right = 0;
        int sum = 0;
        while (right < k) {
            sum += nums[right++];
        }
        
        //right == k now, sum stores the sum from 0 to k-1
        int index = 0;
        res[index++] = sum;
        
        while (right < n) {
            // 0    k-1
            // left  right: left = right - k +1
            int left = right -k;
            sum -= nums[left];
            sum += nums[right++];
            res[index++] = sum;
        }
        return res;
    }
};

