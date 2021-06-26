//lt use of set, construct the consecutive sequence +1-1 with the set membership check
//shaun read and understand
//runtime 8ms, faster than 97.60%, mem less than 57%
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set1;
        for (int i : nums) {
            set1.insert(i);
        }

        int longestStreak = 0;

        for (int i : set1) {
            if (!set1.count(i-1)) {
                int currentNum = i;
                int currentStreak = 1;

                while (set1.count(currentNum+1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
    
};
