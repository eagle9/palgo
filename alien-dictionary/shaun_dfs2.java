/*
Runtime: 5 ms, faster than 53.53% of Java online submissions for Alien Dictionary.
Memory Usage: 27.1 MB, less than 5.96% of Java online submissions for Alien Dictionary.
shaun java code, based on grandyang topological dfs idea
instead of build a graph as a list of nodes(with its directed neighbors), the problem at hand can only help us to gather 2 letter ordering rules from checking words[i] and words[i+1], so we build the directed graph with kind of addjacency matrix. the nodes of the graph will a set of the letters. 

the 2 char ordering can be represented with HashSet<char []>, but not TreeSet<char[]> since char[] does not implemented comparable interface. 
however TreeSet is slower than HashSet, i don't think TreeSet is needed to store 2 letter ordering rules
*/
public class Solution {
    public String alienOrder(String[] words) {
        
        Set<char []> set = new HashSet<>();//set of 2 char order rule
        //Set<String> set = new TreeSet<>();//set of 2 char order rule, treeset is slower than hashset because of ordering keys
        Set<Character> ch = new HashSet<>(); //set of all chars
        int [] in = new int[26]; //indegree  in[c - 'a']
        //int [] in = new int[256]   //indegree in[c], use asc ii value directly
        Queue<Character> q = new LinkedList<>();
        String res = "";
        
        for (String word: words) 
            for (char c: word.toCharArray()) ch.add(c);
        //go through words, check i and i+1 word pair to gather 2 char order rule
        for (int i = 0; i <= words.length-2; i++) {
            int minLen = Math.min(words[i].length(), words[i+1].length());
            int j = 0;
            for ( ; j < minLen; ++j) {
                char c1 = words[i].charAt(j), c2 = words[i+1].charAt(j);
                if ( c1 != c2) {  //found a order rule
                    set.add(new char [] {c1,c2});
                    break; //done, no need to check more j
                }
            }
            if (j == minLen && words[i].length() > words[i+1].length()) return ""; //why
        }
        
        for (char [] pair: set) in[pair[1]-'a'] ++; //populate indegree table
        
        for (char c: ch) {
            if (in[c-'a'] ==0) {
                q.offer(c);
                res += c;
            }
        }
        while (!q.isEmpty()){
            char c = q.poll();
            for (char [] pair: set) {
                char c1 = pair[0], c2 = pair[1];
                if (c1 == c) {
                    --in[c2-'a'];
                    if (in[c2-'a'] ==0) {
                        q.offer(c2);
                        res += c2;
                    }
                    
                }
            }
        }
        return res.length() == ch.size()? res : "";
    }
}

