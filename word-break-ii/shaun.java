//shaun first try with dfs
//wrong answer
//Feb 8 2019
class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> dict = new HashSet<>();
        dict.addAll(wordDict);
        
        Set<String> visited = new HashSet<>();
        List<String> res = new ArrayList<>();
        
        helper(s,dict, visited, res,"", 0);
        return res;
    }
    
    private void helper(String s, Set<String> dict, Set<String> visited,  List<String> res, String cur,int start) {
        if (start == s.length()) {
            if (!visited.contains(cur)) {
                res.add(cur);
                visited.add(cur);
            }
            return;
        }
        
        for (int i = start+1; i <= s.length(); i++) {
            String word = s.substring(start,i);
            if (dict.contains(word)) {
                cur = (cur.length() > 0)? cur + " " + word : word;
                helper(s, dict,visited, res, cur,i);
                //res.remove(res.size()-1);
                
            }
        }
         
    }
}
