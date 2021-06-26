//grandyang and shaun same idea, from end of string to begin, consider carry and contribution 
//do not forget carry at last step
//for java note the ascii to char conversion
//runtime 0ms, faster than 100%, mem less than 82%
class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder res = new StringBuilder();

            int m = num1.length(), n = num2.length(), i = m - 1, j = n - 1, carry = 0;

            while (i >= 0 || j >= 0) {
                int a = i >= 0 ? num1.charAt(i--) - '0' : 0; //num1 contribution
                int b = j >= 0 ? num2.charAt(j--) - '0' : 0; //num2 contribution
                int sum = a + b + carry;
                //res.insert(res.begin(), sum % 10 + '0');
                char ch = (char)(sum % 10 + '0');
                res.append(ch);
                carry = sum / 10;
                //System.out.println("digit = " + ch + " carry = " + carry);
            }
            if (carry > 0) res.append((char)(carry + '0'));
            // res = 335
            return res.reverse().toString();
    }
}


