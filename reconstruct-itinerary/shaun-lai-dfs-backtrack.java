/*
//lai brute force graph and dfs with backtracking
// more intuitive than hua's 
// cutting: src to vector of dests, sort destinations
//  grow path node by node till we reach required len
//  backtracking when not success
//runtime 20ms, faster than 96%, mem less than 98%

Runtime: 5 ms, faster than 79.88% of Java online submissions for Reconstruct Itinerary.
Memory Usage: 39.8 MB, less than 88.06% of Java online submissions for Reconstruct Itinerary.

may 2020,shaun from c++, several bugs and exceptions
*/
class Solution {
    public List<String> findItinerary(List<List<String>> tickets) { 
        
        //graph_: a node to all its children(destinations)
        for(List<String> v2 : tickets) {
            List<String> list = graph.getOrDefault(v2.get(0), new ArrayList<>());
            list.add(v2.get(1));
            graph.put(v2.get(0), list);
        }
        //sort each node's children
        for(String node : graph.keySet()) {
            List<String> list = graph.get(node);
            Collections.sort(list);
        }
        
        //final String kStart = "JFK";
        
        List<String> path = new ArrayList<>();
        path.add("JFK");
        int len = 1+ tickets.size(); //if 1 ticket, how many airports? 2
        if (dfs("JFK",path, len)) return path;
        
        return new ArrayList<>();
    }

    // src -> {dst1, dest2, ..., destn}
    private HashMap<String, List<String>> graph = new HashMap<>();  
    
    private boolean dfs(String src, List<String> path, int len) {
        if (path.size() == len) return true;
        
        List<String> dests = graph.get(src);
        if (dests != null) {
            //try each dest in order, once used, remove it
            for (int i = 0; i < dests.size(); ++i) {
                String dest = dests.get(i);
                dests.remove(i);
                path.add(dest);
                if (dfs(dest, path, len)) return true;
                path.remove(path.size()-1);
                dests.add(i, dest);

            }
        }
        return false;
    }
};

