//shaun own code two pointer idea, accepted first sub, 
//runtime 8ms, faster than 99%, mem less than 80%
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        vector<int> res(2);
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                res[0] = left+1;
                res[1] = right+1;
                break;
            }
            if (sum < target) left++;
            else right--;
        }
        //not found, assume exactly one solution
        return res;
        
    }
};
