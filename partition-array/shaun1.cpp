//shaun's own idea and code, two pointer template kind of, 
//beats 72% subs at lintcode
class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
	//elements < k in front, elements >=k in the back
	//return index of first element >=k
	//0 -- res-1     res--  len-1
    int partitionArray(vector<int> &nums, int k) {
        int i = 0; //index that stores elements < k
        for (int j = 0; j < nums.size(); ++j) {
        	if (nums[j] < k) {
        		int temp = nums[i];
        		nums[i] = nums[j];
        		nums[j] = temp;
        		i++;
        	}
        }
        return i;
    }
};
