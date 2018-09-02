// jz sv algo bootcamp dp +DFS version
//Your submission beats 51.60% Submissions!

public class Solution {
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
     
    List<String> res = new ArrayList<String>();
    List<List<Integer>>f = new ArrayList<>();
    int n;
    
    void dfs(int p, String s, String now) {
        if (p == n) {
            res.add(now);
            return;
        }
        
        if (p > 0) {
            now += " ";
        }
        
        for (int i : f.get(p)) {
            dfs(i, s, now + s.substring(p, i));
        }
    }
    
    public List<String> wordBreak(String s, Set<String> dict) {
        n = s.length();
        int i, j;
        for (i = 0; i < n; ++i) {
            f.add(new ArrayList<>());
        }
        
        for (i = n - 1; i >= 0; --i) {
            for (j = i + 1; j <= n; ++j) {
                if (dict.contains(s.substring(i, j))) {
                    if (j == n || f.get(j).size() > 0) {
                        f.get(i).add(j);
                    }
                }
            }
        }
        
        dfs(0, s, "");
        return res;
    }
}
