/*shaun owen try with dfs
//wrong answer first
then read linhuchong code, accepted after one fix
//Feb 8 2019
//s = word + suffix, word in dict, recur on suffix,  suffix len == 0 exit
Runtime: 11 ms, faster than 48.97% of Java online submissions for Word Break II.
*/
class Solution {
  public List<String> wordBreak(String s, List<String> wordDict) {
      //word list to set for quick 
      Set<String> dict = new HashSet<>();
      dict.addAll(wordDict);
      
      
      List<String> res = new ArrayList<>();
      //need a memo
      Map<String, List<String>> memo = new HashMap<>();
      return helper(s,dict, memo);
      
  }
  
  private List<String> helper(String s, Set<String> dict, Map<String,List<String>> memo) {
	  int len = s.length();
      List<String> res = new ArrayList<>();
	  if (len == 0) {
		  return res;
	  }
      
	  if (memo.containsKey(s)) return memo.get(s);
	  
      //key to add the following line
      if (dict.contains(s)) {
          res.add(s);
      }
      //len > 0,   s from 0 to len-1
      for (int i = 1; i <= len-1; i++) {
          String word = s.substring(0,i);
          String suffix = s.substring(i);
          if (dict.contains(word)) {
              List<String> res2 = helper(suffix,dict,memo);
              for (String word2: res2) {
            	  res.add(word + " " + word2);
              }
              
          }
      }
      memo.put(s, res);
      return res;
       
  }
}
