//grandyang idea, runtime 5ms, faster than 100%
//keypoints: 1) figure out the jumps
// 2) come up with recursive dfs helper
// 3) figure out the rotation symetrical properties and it use to simplify the search
class Solution {
    public int numberOfPatterns(int m, int n) {
        int res = 0;
        //use this hash to reduce the reuse of number, and mid number is already used
        boolean [] visited = new boolean[10];
        // 1 2 3
        // 4 5 6
        // 7 8 9
        //2d array to store the mid number from i to j. if the value is 0, that means the jump from i to j does not go through any number, which mean okay to jump. 
        int [][] jumps = new int[10][10];
        jumps[1][3] = jumps[3][1] = 2;
        jumps[1][7] = jumps[7][1] = 4;
        jumps[3][9] = jumps[9][3] = 6;
        jumps[7][9] = jumps[9][7] = 8;
        jumps[4][6] = jumps[6][4] = 5;
        jumps[2][8] = jumps[8][2] = 5;
        jumps[1][9] = jumps[9][1] = 5;
        jumps[3][7] = jumps[7][3] = 5;
        //other jumps will be 0, which means you can jump to next
        
        res += helper(1, 1, 0, m, n, jumps, visited) * 4;
        res += helper(2, 1, 0, m, n, jumps, visited) * 4;
        res += helper(5, 1, 0, m, n, jumps, visited);
        return res;
    }
    //to use start as one key in the solution
    private int helper(int start, int len, int res, int m, int n, int [][] jumps, boolean [] visited) {
        /* //grandyang
        if (len >= m) ++res;
        ++len;
        if (len > n) return res;
        visited[start] = true;
        for (int next = 1; next <= 9; ++next) {
            int jump = jumps[start][next];
            if (!visited[next] && (jump == 0 || visited[jump])) {
                res = helper(next, len, res, m, n, jumps, visited);
            }
        }
        
        visited[start] = false;
        return res;
        */
        //shaun's, it is not that easy 
        //the helper is to do
        if (len >= m) res++; //think about how we increase res???? when we find a valid number series
        len++; // start is used, we only try start when it is valid to add
        //visited[start] = true;  //--> wrong answer
        //what is the exit of recursion????
        if (len > n) {
            return res;
        }
        
        //use start and try next number
        visited[start] = true;
        for (int next = 1; next <=9; next++) {
            int mid = jumps[start][next];
            if (!visited[next] && (visited[mid] || mid == 0)) {
                //i can valid to go on
                res = helper(next, len, res, m, n, jumps,visited);
            }
        }
        visited[start] = false; //backtracking, why????
        //we need to return res here
        return res;
        
    }
}
