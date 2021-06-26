//adpated from jiadai c++,Your submission beats 28.80% Submissions!

class Solution {
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    public List<List<String>> partition(String s) {
        // write your code here
        List<List<String>> result = new ArrayList<>();
        int n = s.length(); //s.size() in c++
        if (n == 0) {
            return result;
        }

        boolean [][] isPalindrome = new boolean[n][n];
        for (int j = 0; j < n; ++j) {
            for (int i = j; i >= 0; --i) {
                //if (s[i] == s[j] && (j - i < 2 || isPalindrome[i + 1][j - 1])) { //c++
                if (s.charAt(i) == s.charAt(j) && (j - i < 2 || isPalindrome[i + 1][j - 1])) {
                    isPalindrome[i][j] = true;
                }
            }
        }
        List<String> path = new ArrayList<>();
        dfs(s, 0, isPalindrome, path, result);
        return result;
    }
    private void dfs(String s, int start, boolean[][] isPalindrome, List<String> path, List<List<String>> result) {
        if (start == s.length()) {
            result.add(new ArrayList<String>(path));
            return;
        }
        
        for (int i = start; i < s.length(); ++i) {
            if (isPalindrome[start][i]) {
                //path.push_back(s.substr(start, i - start + 1));
                //c++ string.substr(start,len) return a string that starts at character position pos and spans len characters (or until the end of the string, whichever comes first).
                path.add(s.substring(start, i + 1)); //java String substring(startIndex, endIndex)
                dfs(s, i + 1, isPalindrome, path, result);
                path.remove(path.size()-1);
            }
        }
    }
};
