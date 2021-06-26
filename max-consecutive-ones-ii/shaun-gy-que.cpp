//address follow up with infinite elements from stream
//only 1 pass, time O(n), space O(k)
//runtime 36ms, faster than 88%, mem less than 50%
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, left = 0, k = 1;
        queue<int> q; //q stores the zero element index
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) q.push(right);
            if (q.size() > k) { //only keep last k 0-element indexes
                left = q.front() + 1; q.pop();
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
//one pass, flip 1 only, what if flip k bits? 
class Solution1 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, cur = 0, cnt = 0;
        for (int num : nums) {
            ++cnt;
            if (num == 0) {
                cur = cnt;
                cnt = 0;
            } 
            res = max(res, cnt + cur);
        }
        return res;
    }
};
/*
count0 can be 1

shaun first try wrong answer
how to deal with the followup 
*/
class Solution00 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count0 = 0;
        int count1 = 0, maxCount = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                count1++;
                
            }else { //==0
                count0++;
                if (count0 <= 1) {
                    count1++;
                }else { // ==0 and count0 > 1 now
                    maxCount = max(maxCount, count1);
                    count0 = 0;
                    count1 = 0;
                }
            }
        }
        maxCount = max(maxCount, count1);
        return maxCount;
    }
};
