//grandyang idea2, shaun java code, bad code, key point, beware of index outbound issue
//beats 20%
class Solution1 {
    public String reverseStr(String s, int k) {
        int n = s.length();
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < n; i += 2 * k) {
            //reverse s from i to i+k-1, keep i+k to i+2k-1
            int end1 = Math.min(n, i+k);
            String part1 = s.substring(i,end1);
            String part1r = reverse(part1);
            b.append(part1r);
            
            if (i + k < n) {
                int end2 = Math.min(n, i+2*k); //i+2k?????, you serious!!!!
                String part2 = s.substring(i+k, end2);
                b.append(part2);
            }
           //reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return b.toString();
    }
    
    private String reverse(String str) {
        return new StringBuilder(str).reverse().toString();
        //or while (left < right) { }
    }
}

//grandyang idea2, shaun's better java code, beats 62%, cleaner code
class Solution {
    public String reverseStr(String s, int k) {
        char [] c = s.toCharArray();
        int n = c.length;
        for (int i = 0; i < n; i += 2 * k) {
           reverse(c,i, Math.min(i + k-1, n-1));
        }
        return String.valueOf(c);
    }
    private void reverse(char [] c, int left, int right) {
        while (left < right) {
            char temp = c[left];
            c[left] = c[right];
            c[right] = temp;
            left++;
            right--;
        }
    }
}
