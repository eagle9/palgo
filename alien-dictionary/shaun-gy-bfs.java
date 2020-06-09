/*
Runtime: 5 ms, faster than 53.53% of Java online submissions for Alien Dictionary.
Memory Usage: 27.1 MB, less than 5.96% of Java online submissions for Alien Dictionary.
shaun java code, based on grandyang topological dfs idea
instead of build a graph as a list of nodes(with its directed neighbors), the problem at hand can only help us to gather 2 letter ordering rules from checking words[i] and words[i+1], so we build the directed graph with kind of addjacency matrix. the nodes of the graph will a set of the letters. 

the 2 char ordering can be represented with HashSet<char []>, but not TreeSet<char[]> since char[] does not implemented comparable interface. 
however TreeSet is slower than HashSet, i don't think TreeSet is needed to store 2 letter ordering rules

4/26/2020 added a test case fix
Runtime: 32 ms, faster than 5.05% of Java online submissions for Alien Dictionary.
Memory Usage: 40.5 MB, less than 5.41% of Java online submissions for Alien Dictionary.
*/

public class Solution {
    public String alienOrder(String[] words) {
        
        Set<String> set = new HashSet<>();//set of 2 char order rule, HashSet or TreeSet, does not matter, TreeSet is slower because of the ordering
        //Set<String> set = new TreeSet<>();//set of 2 char order rule, treeset is slower than hashset because of ordering keys
        Set<Character> ch = new HashSet<>(); //set of all chars
        int [] in = new int[256]; //indegree
        Queue<Character> q = new LinkedList<>();
        String res = "";
        
        for (String word: words) 
            for (char c: word.toCharArray()) ch.add(c);
        //go through words, check i and i+1 word pair to gather 2 char order rule
        for (int i = 0; i <= words.length-2; i++) {
            String word1 = words[i], word2 = words[i+1];
            // Check that word2 is not a prefix of word1.
            if (word1.length() > word2.length() && word1.startsWith(word2)) {
                return "";
            }
            int minLen = Math.min(word1.length(), word2.length());
            int j = 0;
            for ( ; j < minLen; ++j) {
                char c1 = words[i].charAt(j), c2 = words[i+1].charAt(j);
                if ( c1 != c2) {  //found a order rule
                    set.add(c1+ "" +c2);
                    break; //done, no need to check more j
                }
            }
            
            //if (j == minLen && words[i].length() > words[i+1].length()) return ""; //why?? because: the following is impossible, no this statement, accepted too
            //words[i]:  aaa
            //words[i+1]:aa
            
        }
        
        for (String pair: set) in[pair.charAt(1)] ++; //populate indegree table
        
        for (char c: ch) {
            if (in[c] ==0) {
                q.offer(c);
                res += c;
            }
        }
        while (!q.isEmpty()){
            char c = q.poll();
            for (String pair: set) {
                char c1 = pair.charAt(0), c2 = pair.charAt(1);
                if (c1 == c) {
                    --in[c2];
                    if (in[c2] ==0) {
                        q.offer(c2);
                        res += c2;
                    }
                    
                }
            }
        }
        return res.length() == ch.size()? res : "";
    }
}

