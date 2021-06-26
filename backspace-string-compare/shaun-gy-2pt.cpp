/*grandyang two pointers, 
shaun came up the same idea loop from end to begin

runtime 0ms, faster than 100%, mem less than 63%
not easy to get details right, or get details ight, complex if and while conditions
*/
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = (int)S.size() - 1, j = (int)T.size() - 1, cnt1 = 0, cnt2 = 0;
        while (i >= 0 || j >= 0) {
            //if # or cnt1 > 0, keep backspace deleting(i--), update cnt1
            while (i >= 0 && (S[i] == '#' || cnt1 > 0)) {
                if (S[i--] == '#') ++cnt1;
                else --cnt1;
            }
            while (j >= 0 && (T[j] == '#' || cnt2 > 0)) {
                T[j--] == '#' ? ++cnt2 : --cnt2;
            }
            //done backspace deleting now
            //case 1, reach begin, i < 0 or j < 0
            if (i < 0 || j < 0) return i == j;
            
            //compare 
            if (S[i--] != T[j--]) return false;
        }
        return i == j;
    }
};
