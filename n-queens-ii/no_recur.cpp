/*
http://www.cnblogs.com/TenosDoIt/p/3801621.html
Runtime: 4 ms, faster than 100.00% of C++ online submissions for N-Queens II.
Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for N-Queens II.
*/

class Solution {
private:
    int res;
public:
    int totalNQueens(int n) {
        vector<int> state(n, -1);
        res = 0;
        helper(state, 0);
        return res;
    }
    void helper(vector<int> &state, int row)
    {//放置第row行的皇后
        int n = state.size();
        if(row == n)
        {
            res++;
            return;
        }
        for(int col = 0; col < n; col++)
            if(isValid(state, row, col))
            {
                state[row] = col;
                helper(state, row+1);
                state[row] = -1;;
            }
    }
     
    //判断在row行col列位置放一个皇后，是否是合法的状态
    //已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
    bool isValid(vector<int> &state, int row, int col)
    {
        for(int i = 0; i < row; i++)//只需要判断row前面的行，因为后面的行还没有放置
            if(state[i] == col || abs(row - i) == abs(col - state[i]))
                return false;
        return true;
    }
 
};
