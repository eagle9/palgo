//grandyang
//shaun read and understand
//runtime 4ms, faster than 90%, mem less than 46%
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        
        int sign = 1, base = 0, i = 0, n = str.size();
        //skip leading space
        while (i < n && str[i] == ' ') ++i;
        
        //deal with + - before digits
        if (i < n && (str[i] == '+' || str[i] == '-')) {
            sign = (str[i++] == '+') ? 1 : -1;
        }
        
        
        while (i < n && str[i] >= '0' && str[i] <= '9') {
            //dealing with number(base) out of range of 32bit
            //  INT_MAX/10 * 10 will be + (str[i] - '0')
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            base = 10 * base + (str[i++] - '0');
        }
        
        return base * sign;
    }
};
