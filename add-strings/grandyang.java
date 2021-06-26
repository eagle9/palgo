public class Solution {
    //grandyang idea, shaun java,  beats 60%
    public String addStrings(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
        int m = num1.length(), n = num2.length(), i = m - 1, j = n - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            //key point: when i is not in bound, contributes 0
            int a = (i >= 0) ? num1.charAt(i--) - '0' : 0;
            int b = (j >= 0) ? num2.charAt(j--) - '0' : 0;
            
            int sum = a + b + carry;
            //System.out.println(a + " --- " + b + " -- " + sum);
            //sb.insert(0, sum % 10 + '0'); //wrong answer
            sb.insert(0, String.valueOf(sum % 10));
            carry = sum / 10;
        }
        //System.out.println(sb);
        return carry == 1? "1" + sb.toString() : sb.toString();
    }
};
