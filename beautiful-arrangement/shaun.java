public class Solution {
    /**
     * @param N: The number of integers
     * @return: The number of beautiful arrangements you can construct
     */
     //grandyang idea, shaun own code, beats 71%
     //draw test, it is very helpful
    public int countArrangement(int N) {
        // Write your code here
        boolean [] visited = new boolean[N+1];
        helper(visited, N,1);
        return count;
    }
    private int count = 0;
    //@visited: mark i (1 to N) is visited or not
    //@N: is the number bound
    //@pos: pos to consider, place i (1 to N)
    private void helper(boolean [] visited, int N, int pos) {
        //exit condition
        if (pos > N) {
            count++;
            return;
        }
        //try 1 to N at pos + 1
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && ((i % pos == 0) || (pos % i == 0))) {
                visited[i] = true;
                helper(visited,N,pos+1);
                visited[i] = false; //kep point: restore is needed
            }
        }
            
    }
    
}

/*
test when N ==2
      h(v,2,1)
      /i=1   \ i=2
    h(v,2,2)    h(v,2,2)
    /i=1  \i=2    /i=1    \ i=2
           h(v,2,3)
           count ++, twice
*/
