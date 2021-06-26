//shaun java code from c++
//idea check c++ code
//runtime 45ms, faster than 64%, mem less than 76%
// java Queue is abstract, = new LinksedList<>()
// push is offer, front is peek, pop is poll, empty --isEmpty
// vector is List, push_back  ---- add
// unordered_set  --- HashSet,  insert --- add
class Solution {
    public int numBusesToDestination(int[][] routes, int S, int T) {
        if (S == T) return 0; //no need to get on bus
        
        Map<Integer,List<Integer>> stop2bus = new HashMap<>();
        for (int bus = 0; bus < routes.length; ++bus) {
            for (int stop: routes[bus]) {
                stop2bus.putIfAbsent(stop, new ArrayList<Integer>());
                stop2bus.get(stop).add(bus);
            }
        }
        
        //bfs level by level from S to T
        Queue<Integer> q = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        q.offer(S);
        int buses = 0;
        while (!q.isEmpty()) {
            buses++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int stop = q.peek(); q.poll();
                
                for (int bus: stop2bus.get(stop)) {
                    if (visited.contains(bus)) continue;
                    visited.add(bus);
                    for (int next: routes[bus]) {
                        if (next == T) return buses;
                        
                        //not visited
                        q.offer(next);
                        
                    }
                    
                }
            }
            
            
        }
        //not yet reach T, not possible, return -1
        return -1;
    }
}


