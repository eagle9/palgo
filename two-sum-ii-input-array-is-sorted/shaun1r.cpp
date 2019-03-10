//shaun's first try, accepted, this one is pretty easy indeed
//runtime 8ms, faster than 99%
//two pointers, O(n) time and O(1) space
class Solution {
public:
    vector<int> twoSum1(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> res;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            
            if ( sum == target) {
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }else if (sum < target) {
                left++;
            }else {
                right--;
            }
        }
        return res;
    };
    
    //shaun try binary search, wrong answer, this way you are trying to beat O(n)
    //really???? you can do that????
    //for each numbers[i], other = target - numbers[i], binary search other
    //O(nlogn), actually worse than two pointers
    vector<int> twoSum2(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> res;
        while (left + 1 < right) {
            int sum = numbers[left] + numbers[right];
            int mid = left + (right - left)/2;
            if ( sum == target) {
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }else if (sum < target) {
                left = mid;
            }else {
                right= mid;
            }
        }
        //left + 1 == right
        int sum = numbers[left] + numbers[right];
        if ( sum == target) {
            res.push_back(left+1);
            res.push_back(right+1);
            return res;
        }
        return res;
    }
};
