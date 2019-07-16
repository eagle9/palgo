//grandyang and shaun stack idea, use helper function
//O(n) space and O(n) time, n is length of string
//runtime 4ms, faster than 72%, mem less than 45%
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return helper(S) == helper(T);      
    }
    string helper(string str) {
        string res = "";
        for (char c : str) {
            if (c == '#') {
                if (!res.empty()) res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        return res;
    }
};
