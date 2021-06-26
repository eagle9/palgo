//jiadai c++
//Your submission beats 93.40% Submissions!
//Your submission beats 52.60% Submissions!
class Solution {
public:
    /*
     * @param nums an array of Integer
     * @param target = nums[index1] + nums[index2]
     * @return [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        vector<int> result(2);
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            if (nums[start] + nums[end] == target) {
                result[0] = start + 1;
                result[1] = end + 1;
                break; //found it, exit loop
            }
            else if (nums[start] + nums[end] > target) {
                --end; //look for smaller numbers, go smaller
            }
            else {
                ++start; //look for larger numbers, go larger
            }
        }
        
        return result;  //found result or empty
    }
};
