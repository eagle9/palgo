//linhuchong bfs + dfs idea, shaun adapted his java code to leetcode
//runtime 171ms, faster than 35%, mem less than 81%
//bfs is easy to understand, dfs not understood
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> dict = new HashSet<>();
        dict.addAll(wordList);
        if (dict.contains(endWord))
            return findLadders(beginWord, endWord, dict);
        else 
            return new ArrayList<>();
    }

    public List<List<String>> findLadders(String start, String end,
            Set<String> dict) {
        List<List<String>> ladders = new ArrayList<List<String>>();
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        Map<String, Integer> distance = new HashMap<String, Integer>();

        dict.add(start);
        dict.add(end);
 
        bfs(map, distance, start, end, dict);
        
        List<String> path = new ArrayList<String>();
        
        dfs(ladders, path, end, start, distance, map);

        return ladders;
    }
    
    
    //to find all ladders, dfs from end to start, path as cursor
    void dfs(List<List<String>> ladders, List<String> path, String crt,
            String start, Map<String, Integer> distance,
            Map<String, List<String>> map) {
        
        path.add(crt);
        if (crt.equals(start)) {
            List<String> path1 = new ArrayList<>(path);
            Collections.reverse(path1);
            ladders.add(path1);
            //return;
        }
        
        for (String parent : map.get(crt)) { //map store list of parent, from start to end
            
            if (distance.containsKey(parent) && distance.get(crt) == distance.get(parent) + 1) { 
                dfs(ladders, path, parent, start, distance, map);
            }
            
           
        }           
         path.remove(path.size() - 1);
       
    }

    //to find all ladders, dfs from end to start, path as cursor
    void dfs2(List<List<String>> ladders, List<String> path, String crt,
            String start, Map<String, Integer> distance,
            Map<String, List<String>> map) {
        //add current node to path, from end to start
        path.add(crt);
        if (crt.equals(start)) {
            List<String> path1 = new ArrayList<>(path);
            Collections.reverse(path1);
            ladders.add(path1);
            //return;
        } else {
            for (String parent : map.get(crt)) { //map store list of parent, from start to end
                if (distance.containsKey(parent) && distance.get(crt) == distance.get(parent) + 1) { 
                    dfs(ladders, path, parent, start, distance, map);
                }
            }           
        }
        path.remove(path.size() - 1);
    }

    //bfs find the shortest path from start to end, with dict
    //populate distance, node --> its distance from start
    //populate map, node -> list of its parent, from start to end
    void bfs(Map<String, List<String>> map, Map<String, Integer> distance,
            String start, String end, Set<String> dict) {
        Queue<String> q = new LinkedList<String>();
        q.offer(start);
        distance.put(start, 0); //store distance from start, also acts as visited
        for (String s : dict) {
            map.put(s, new ArrayList<String>());
        }
        
        while (!q.isEmpty()) {
            String crt = q.poll();

            List<String> nextList = expand(crt, dict);
            for (String next : nextList) {
                //cur ----> next
                map.get(next).add(crt); // map stores all parent words of next
                if (!distance.containsKey(next)) {
                    distance.put(next, distance.get(crt) + 1);
                    q.offer(next);
                }
            }
        }
    }

    List<String> expand(String crt, Set<String> dict) {
        List<String> expansion = new ArrayList<String>();

        for (int i = 0; i < crt.length(); i++) {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch != crt.charAt(i)) {
                    String expanded = crt.substring(0, i) + ch
                            + crt.substring(i + 1);
                    if (dict.contains(expanded)) {
                        expansion.add(expanded);
                    }
                }
            }
        }

        return expansion;
    }
}
