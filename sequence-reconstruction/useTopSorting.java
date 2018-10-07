//jz Your submission beats 93.00% Submissions!
/*
create a directed graph according to seqs 

for seq = [1, 2, 3], add vertex 1, 2, 3, and edges (1, 2), (2, 3)

use indegree to store indegree of each vertex），use graph(sucset) to keep it succeeding vertex

do topological sorting (bfs and q size ==1 to ensure unique),  compare org and the sorted list

*/
public class Solution {
    /**
     * @param org a permutation of the integers from 1 to n
     * @param seqs a list of sequences
     * @return true if it can be reconstructed only one or false
     */
    public boolean sequenceReconstruction(int[] org, int[][] seqs) {
        // set of following numbers
        Map<Integer, Set<Integer>> graph = new HashMap<>();
        //Map<Integer, Integer> indegree = new HashMap<>();
    	
    	//initialize directed graph and indegree for each vertex
        for (int num : org) {
            graph.put(num, new HashSet<Integer>());
            //indegree.put(num, 0);
        }
        int n = org.length;
        int [] indegree = new int[n+1];
        
        int count = 0; //count all vertex in seqs
        for (int[] seq : seqs) {
            count += seq.length;
            
            for (int i = 0; i < seq.length; i++) {
                if (seq[i] <= 0 || seq[i] > n) //number not in org
                    return false;
                if (i==0) continue;
                //seq[i-1] --> seq[i]
                Set<Integer> set = graph.get(seq[i-1]);
                if (set.add(seq[i])) {
                    //indegree.put(seq[i], indegree.get(seq[i]) + 1);
                    indegree[seq[i]] +=1;
                }
            }
        }

        // total numbers in seqs < total numbers in org
        if (count < n)
            return false;
		
        Queue<Integer> q = new ArrayDeque<Integer>();
        /*
        for (int v : indegree.keySet()) {
            if (indegree.get(v) == 0) {
                //q.add(v);
                q.offer(v);
            }
        }*/
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }
        int cnt = 0;
        while (q.size() ==1) { //why? unique topological sorting
            int v = q.poll();
            for (int next : graph.get(v)) {
                /*indegree.put(next, indegree.get(next) - 1);
                if (indegree.get(next) == 0) 
                    q.add(next);
                    */
                indegree[next] -=1;
                if (indegree[next] == 0) {
                    q.offer(next);
                }
            }
            //the order we get v is in topological sorting
            if (v != org[cnt]) {
                return false;
            }
            cnt++;
        }
		
        return cnt == n;
    }
}
