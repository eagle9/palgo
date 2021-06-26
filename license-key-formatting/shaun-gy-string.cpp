//grandyang idea
//do as problem required, using data structure, test with examples
//runtime 4ms, faster than 99.86%, mem less than 55%
/*
Input: S = "5F3Z-2e-9-w", K = 4

W9E2-Z3F5-
W9E2-Z3F5     pop -
5F3Z-2E9W  reverse

*/
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int cnt = 0; //count of valid chars, no - char
        int n = S.size();
        //from tail obivious, since last group might not be full
        for (int i = n - 1; i >= 0; --i) {
            char c = S[i];
            if (c == '-') continue; //skip - char
            if (c >= 'a' && c <= 'z') c -= 32; //lower to upper case
            res.push_back(c);
            if (++cnt % K == 0) res.push_back('-'); //add separate
        }
        //critical to deal with - char at back
        if (!res.empty() && res.back() == '-') res.pop_back();
        //reverse
        //return string(res.rbegin(), res.rend());
        reverse(res.begin(), res.end());
        return res;
    }
};
