//shaun own idea and code, accepted after fixing two bugs
//bug 1, should go from end to begin of input strings
//bug 2, carry set to 0 once used
//clever move, if contribute
//runtime 4ms, faster than 87%, mem less than 72%
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length(), n = b.length();
        int carry = 0;
        string res;
        //bug 1, be sure to look at char from end to begin of the input strings
        for (int i = 0; i < m || i < n; ++i) {
            int digit = carry;
            carry = 0; //bug, you have to set carry to 0 once you included it
            
            //if first input string can contribute
            if (i < m) {
                digit += a[m-1-i] - '0';
                if (digit == 2) {
                    digit = 0;
                    carry = 1;
                }
            }
            //if the second input string can contribute
            if (i < n) {
                digit += b[n-1-i] - '0';
                if (digit == 2) {
                    digit = 0;
                    carry = 1;
                }
            }
            res.insert( res.begin(), digit + '0');
        }
        if (carry) res.insert( res.begin(), carry + '0');
        return res;
    }
};
