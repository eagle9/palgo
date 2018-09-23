//https://lxp1991.github.io/2017/12/07/LeetCode-LintCode-Split-String/
//beats 84.20%
public class Solution {
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    public List<List<String>> splitString(String s) {
        // write your code here
        List<List<String>> res = new ArrayList<>();
        if (s == null) return res;
        if (s.length() == 0) {
            res.add(new ArrayList<String>());
            return res;
        }
        dfs(res, new ArrayList<String>(), 0, s);
        return res;
    }
    //cd -- candidate
    private void dfs(List<List<String>> res, List<String> cd, int index, String s) {
        if (index >= s.length()) {
            res.add(new ArrayList<String>(cd));
            return;
        }
        
        for (int i = index; i <= index + 1 && i < s.length(); i++) {
            String sub = s.substring(index, i + 1);
            cd.add(sub);
            dfs(res, cd, i + 1, s);
            cd.remove(cd.size() - 1); //back tracking
        }
        
        
    }
}
