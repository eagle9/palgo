//shaun own idea, accepted after fixing two bugs( on a muddy brain day)
//runtime 4ms, faster than 75%, mem less than 86%
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int n = digits.size();
        int carry = 0;
        for (int i = n-1; i >= 0; --i) {
            int sum = (i == n-1? 1+digits[i]: digits[i]) + carry; // bug 1: miss i == n-1 test
            int d = sum % 10;
            carry = sum /10;
            res.push_back( d);
            
        }
        if (carry) res.push_back(carry); //bug 2
        reverse(res.begin(), res.end());
        return res;
    }
};
