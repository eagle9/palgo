//given courses from 0 to n-1, and prerequisites list such as [i,pre] pre ---> i
//figure out if it is possible to finish all the courses
//topogical sorted course list, does this list include all courses? 
// or length of the sorted list == n???
//represent the graph:
//node list   0 to n-1, 
// for each node, use edges to all followers from the node

//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

//shaun's update, Your submission beats 92.80% Submissions! at lintcode, beats 65% at leetcode
//
//slightly modified from course schedule solution
public class Solution {
     
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    public int[] findOrder(int numCourses, int[][] prerequisites) {
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
        List<Integer> sorted = new ArrayList<>();
        while(!queue.isEmpty()){
            int course = queue.poll();
            sorted.add(course);
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
        
        //now we have the topogical sorted list
	//read the problem statement fully and clearly get what it means
        //according to problem statement: There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
        
        int n = sorted.size();
        if (n < numCourses)
            return new int[0]; //return empty array
        int [] res = new int[n];
        for (int i = 0; i < n; i++ ) {
            res[i] = sorted.get(i);
        }
        return res;
    }

}
