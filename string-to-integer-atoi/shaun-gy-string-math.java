/*
Runtime: 1 ms, faster than 100.00% of Java online submissions for String to Integer (atoi).
Memory Usage: 39.4 MB, less than 5.59% of Java online submissions for String to Integer (atoi).
Next challenges:


*/
class Solution {
    public int myAtoi(String str) {
        if (str.length() == 0) return 0;

        int sign = 1, base = 0, i = 0, n = str.length();
        //skip leading space
        while (i < n && str.charAt(i) == ' ') ++i;

        //deal with +/- before digits
        if (i < n && (str.charAt(i) == '+' || str.charAt(i) == '-')) {
            sign = (str.charAt(i) == '+') ? 1 : -1;
            i++; //move to next char
        }


        while (i < n && str.charAt(i) >= '0' && str.charAt(i) <= '9') {
            //dealing with number(base) out of range of 32bit
            //  INT_MAX/10 * 10 will be + (str[i] - '0')
            if (base > Integer.MAX_VALUE / 10 || 
                (base == Integer.MAX_VALUE / 10 && str.charAt(i) - '0' > 7)) {
                return (sign == 1) ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            base = 10 * base + (str.charAt(i) - '0');
            i++;
        }

        return base * sign;

    }
}
