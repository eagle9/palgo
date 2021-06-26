#from jz java, Your submission beats 53.55% Submissions!
class Solution:
    '''
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
    '''
    def solveNQueens(self, n):
        results = []
        if n <= 0:
            return results

        self.search(results, [], n)
        return results

    '''
     * results store all of the chessboards
     * cols store the column indices for each row
    '''
    def search(self,results, cols, n):
        if len(cols) == n:
            results.append(self.drawChessboard(cols))
            return

        for colIndex in range(n):
            if not self.isValid(cols, colIndex):
                continue
            cols.append(colIndex)
            self.search(results, cols, n)
            cols.pop()

    def drawChessboard(self, cols):
        chessboard = []
        for i  in range(len(cols)):
            sb = []
            for j in range(len(cols)):
                sb.append('Q' if j == cols[i] else '.')
            chessboard.append(''.join(sb))
        return chessboard

    def isValid(self, cols, column):
        row = len(cols)
        for rowIndex in range(len(cols)):
            if cols[rowIndex] == column:
                return False
    
            if rowIndex + cols[rowIndex] == row + column:
                return False
    
            if rowIndex - cols[rowIndex] == row - column:
                return False
    
        return True
