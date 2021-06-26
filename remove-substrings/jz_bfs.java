//jz beats 96.20%
//idea is bfs, dfs should work too
public class Solution {
    /**
     * @param s a string
     * @param dict a set of n substrings
     * @return the minimum length
     */
    public int minLength(String s, Set<String> dict) {
        // Write your code here
        Queue<String> que = new LinkedList<String>();
        Set<String> visited = new HashSet<String>();
    
        int min = s.length();
        que.offer(s);
        visited.add(s);

        while (!que.isEmpty()) {
            s = que.poll();
            //for each word in dict, find it in s and remove it, to get new_s
            //s --> new_s is an edge of the underlying graph
            for (String sub : dict) {
                int found = s.indexOf(sub);
                
                //find all sub instances 
                while (found != -1) {
                    String new_s = s.substring(0, found) +
                        s.substring(found + sub.length(), s.length());
                    if (!visited.contains(new_s)) {
                        if (new_s.length() < min) //update min
                            min = new_s.length();
                        que.offer(new_s);
                        visited.add(new_s);
                    }
                    found = s.indexOf(sub, found + 1);
                }
            }
        }
        return min;
    }
}
