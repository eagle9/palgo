
//jz Your submission beats 64.20% Submissions!
//given courses from 0 to n-1, and prerequisites list such as [i,pre] pre ---> i
//figure out if it is possible to finish all the courses
//topogical sorted course list, does this list include all courses? 
// or length of the sorted list == n???
//represent the graph:
//node list   0 to n-1, 
// for each node, use edges to all followers from the node

public class Solution {
    /**
     * @param numCourses a total of n courses
     * @param prerequisites a list of prerequisite pairs
     * @return true if can finish all courses or false
     */
     
     //Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
    public boolean canFinish0(int numCourses, int[][] prerequisites) {
        // edges[i] store the list of nodes from i
        List[] edges = new ArrayList[numCourses];
        //in degree of each node
        int[] degree = new int[numCourses];
        
        for (int i = 0;i < numCourses; i++)
            edges[i] = new ArrayList<Integer>();
            
        for (int i = 0; i < prerequisites.length; i++) {
            degree[prerequisites[i][0]] ++ ;
            edges[prerequisites[i][1]].add(prerequisites[i][0]);
        }

        //enqueue all nodes whose in degree ==0 
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i < degree.length; i++){
            if (degree[i] == 0) {
                queue.add(i);
            }
        }
        
        //bfs 
        int count = 0;
        while(!queue.isEmpty()){
            int course = queue.poll();
            count ++;
            int n = edges[course].size();
            for(int i = 0; i < n; i++){
                int pointer = (int)edges[course].get(i);
                degree[pointer]--;
                if (degree[pointer] == 0) {
                    queue.add(pointer);
                }
            }
        }
        
        return count == numCourses;
    }
    
    //shaun's update, Your submission beats 78.60% Submissions!

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // edges.get(i) store the list of nodes from i
        List<List<Integer>> edges = new ArrayList<>(numCourses);
        //in degree of each node
        int[] degree = new int[numCourses];
        
        for (int i = 0;i < numCourses; i++)
            edges.add(new ArrayList<Integer>());
        
        //[0] has prerequisite [1]  
        // 1 --> 0
        for (int i = 0; i < prerequisites.length; i++) {
            degree[ prerequisites[i][0] ] ++ ;
            edges.get(prerequisites[i][1]).add(prerequisites[i][0]);
        }

        //enqueue all nodes whose in degree ==0 
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i < degree.length; i++){
            if (degree[i] == 0) {
                queue.add(i);
            }
        }
        
        //bfs 
        int count = 0;
        //count is the length of topological sorting list
        while(!queue.isEmpty()){
            int course = queue.poll();
            count ++;
            // n nodes follow course
            int n = edges.get(course).size();
            for(int i = 0; i < n; i++){
                int follower = edges.get(course).get(i);
                //put course to sorted list, now all its followers in degree --
                degree[follower]--;
                if (degree[follower] == 0) {
                    queue.add(follower);
                }
            }
        }
        
        //topogical sorted list length == num of courses
        return count == numCourses;
    }
}
