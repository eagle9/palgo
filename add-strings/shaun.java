public class Solution {
    /**
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
     //shaun own, beats 8%
    public String addStrings(String num1, String num2) {
        // write your code here
        List<Character> res = new ArrayList<>();
        int m = num1.length(), n = num2.length();
        int i = m-1, j = n-1, carry = 0;
        while (i >= 0 && j >= 0) {
            int a = num1.charAt(i) - '0';
            int b = num2.charAt(j) - '0';
            int sum = a+b+carry;
            res.add(0,(char)(sum%10 + '0'));
            carry = sum/10;
            i--;
            j--;
        }
        if (i >= 0) { //num1 longer
            while (i >= 0) {
                int a = num1.charAt(i) - '0';
                int sum = a+carry;
                res.add(0,(char)(sum%10 + '0'));
                carry = sum/10;
                
                i--;
            }
        }
        else { //num2 longer 
            while (j >= 0) {
                int b = num2.charAt(j) - '0';
                int sum = b+carry;
                res.add(0,(char)(sum%10+'0'));
                carry = sum/10;
                
                j--;
            }
        }
		//dont forget carry, result can be 1 digit longer than a and b
        if (carry > 0) {
            res.add(0,(char)(carry+'0'));
        }
        String res1 = "";
        for (Character c: res) {
            res1 += String.valueOf(c);
        }
        return res1;
        
        
        
    }
    
    //shaun modified, beats 8%
    //key point: java int to char,   char to in
    public String addStrings222(String num1, String num2) {
        // write your code here
        List<Character> res = new ArrayList<>();
        int m = num1.length(), n = num2.length();
        int i = m-1, j = n-1, carry = 0;
        while (i >= 0 || j >= 0) {
            int a = (i>=0)? num1.charAt(i) - '0': 0;
            int b = (j>=0)? num2.charAt(j) - '0': 0;
            int sum = a+b+carry;
            res.add(0,(char)(sum%10 + '0'));
            carry = sum/10;
            i--;
            j--;
        }
        
        if (carry > 0) {
            res.add(0,(char)(carry+'0'));
        }
        String res1 = "";
        for (Character c: res) {
            //res1 += String.valueOf(c);
            res1 += c;
        }
        return res1;
        
        
        
    }
}
