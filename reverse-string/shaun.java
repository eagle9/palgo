public class Solution {
    /**
     * @param s: a string
     * @return: return a string
     */
     
     //beats 30.77%
     /*
    public String reverseString(String s) {
        char[] a = s.toCharArray();
        int left = 0, right = a.length-1;
        while (left < right) {
            char temp = a[right];
            a[right] = a[left];
            a[left] = temp;
            left++;
            right--;
        }
        return new String(a);
    }*/
    
    //beats 30.77%
    public String reverseString(String s) {
        StringBuilder sb = new StringBuilder(s);
        //StringBuffer sb = new StringBuffer(s);
        int left = 0, right = sb.length() - 1;
        while (left < right) {
            sb.setCharAt(right, s.charAt(left));
            sb.setCharAt(left, s.charAt(right));
            left++;
            right--;
        }
        return sb.toString();
    }
}
