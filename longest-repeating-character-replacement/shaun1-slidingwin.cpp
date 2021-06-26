//grandyang sliding window idea, shaun read and understand
// keep char count in the sliding window ---> counts
// desirable window ---> can replace k chars to make all chars in the window repeating
// so we track the maxCnt of any char in the window, replace others 
//runtime 8ms, faster than 99.35%, mem less than 78%
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxCnt = 0; //maxCnt stores the max char count in s
        int res = 0, left = 0;
        vector<int> counts(26);
        //int counts[26] = {0}; //store char count in string s, array okay too
        for (int right = 0; right < s.length(); ++right) {
            ++counts[s[right] - 'A']; //expand right
            maxCnt = max(maxCnt, counts[s[right] - 'A']);
            
            //contract left
            //desirable window from left to right, single char
            //choose a char that occurred the most, that's maxCnt
            //number of chars need to be replaced is right-left+1- maxCnt, limit by k
            //the other chars more than k, then contract from left
            while (right - left + 1 - maxCnt > k) {
                --counts[s[left] - 'A']; //char counts in window updated
                ++left;
            }
            //window size - maxCnt ==k, okay to replace with k
            res = max(res, right - left + 1);
        }
        return res;
    }
};
