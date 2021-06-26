//jz idea and java code, runtime 3ms, faster than 83%, mem less than 46%
public class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        if (s == null || s.length() == 0 ) return null;
        List<String> par = new ArrayList<>();
        helper(s, 0, par, res);
        return res;
    }
    private void helper(String s, int start, List<String> par, List<List<String>> res) {
        if (start == s.length()) {
            res.add( new ArrayList<String>(par) );
            return;
        }
        for (int i = start; i < s.length(); i++) {
            String sub = s.substring(start, i+1);
            if (isPalindrome(sub)) {
                par.add(sub);
                helper(s,i+1, par, res);
                par.remove(par.size()-1);
            }
        }
    }
    private boolean isPalindrome(String s) {
        int i = 0, j = s.length()-1;
        while ( i < j ) {
            if (s.charAt(i) != s.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }
}
