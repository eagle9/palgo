//jz idea, shaun read and understand
//but hash initialization is hard to get right
//beats 85%
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        //hash stores prefixSum i sum from 0 to i, map the sum to i
        unordered_map<int, int> hash;
        if (nums.empty()) return {};
        int sum = 0;
        hash[0] = -1; //sum 0, sum from 0 to -1, sum from 0 to 0 will be nums[0]
        //hash[0] is very important here
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            //if (hash.find(sum) != hash.end()) {
            if (hash.count(sum)) {
                vector<int> result;
                // sum from 0 to   j,      hash[sum]
                // sum      0           i
                //                   j+1 ... i   sum to 0
                result.push_back(hash[sum] + 1);
                result.push_back(i);
                return result;
            }
            hash[sum] = i;
        }
        
        vector<int> result;
        return result;
    }
};
