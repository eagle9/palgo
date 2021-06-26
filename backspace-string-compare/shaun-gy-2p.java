//Runtime: 0 ms, faster than 100.00% of Java online submissions for Backspace String Compare.
//shaun off gy idea 2p from back
class Solution {
    public boolean backspaceCompare(String S, String T) {
        int i = S.length()-1, j = T.length()-1;
        int count1 = 0, count2 = 0; //count of # seen from back
        while (i >= 0 || j >= 0) {
            
            //if current char is # or seen # from prev
            while (i >= 0 && (S.charAt(i) == '#' || count1 > 0 )) {
                if (S.charAt(i) == '#') count1++;
                else count1--;
                i--;
            }
            while (j >= 0 && (T.charAt(j) == '#' || count2 > 0 )) {
                if (T.charAt(j) == '#') count2++;
                else count2--;
                j--;
            }
            if (i < 0 || j < 0) return i == j;
            if (S.charAt(i) != T.charAt(j)) return false;
            i--;
            j--;
        }
        return i==j;
    }
}
