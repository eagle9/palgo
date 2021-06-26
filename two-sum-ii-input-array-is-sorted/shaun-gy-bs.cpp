// O(nlgn)
//grandyang binary search, find each number, find target-number in array using binary search
//runtime 8ms, faster than 68%, mem less than 98%
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int t = target - numbers[i], left = i + 1, right = numbers.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == t) return {i + 1, mid + 1};
                else if (numbers[mid] < t) left = mid + 1;
                else right = mid;
            }
        }
        return {};
    }
};
