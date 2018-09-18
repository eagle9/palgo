#jz java non recursive, using stack
#Your submission beats 58.87% Submissions!
class Solution:
    '''
     * @param n: The number of queens
     * @return: All distinct solutions
    '''
    def solveNQueens(self, n):
        results = []
        if n <= 0:
            return results

        # row: col
        queen = [None for i in range(n)]

        # DFS
        stack = []
        row = 0
        col = None
        goNextRow = None

        stack.append(0)
        while stack:
            goNextRow = False
            col = stack.pop()
            while col < n:
                if self.isAvailable(n, queen, row, col):
                    queen[row] = col
                    stack.append(col + 1)
                    goNextRow = True
                    break
                col+=1
        
            if goNextRow:
                if row + 1 == n:
                    results.append(self.drawResult(n, queen))
                else:
                    row+=1
                    stack.append(0)
            else:
                row-=1

        return results

    def drawResult(self, n, queen):
        list1 = []
        for i in range(n):
            q = queen[i]
            str1 = ""
            for j in range(n):
                if j == q:
                    str1 += "Q"
                else:
                    str1 += "."
            list1.append(str1)
        return list1
    
    def isAvailable(self, n, queen, row, col):
        i = 1
        while row - i >= 0:
            prevQ = queen[row - i]
            if col == prevQ:
                return False
            if col - i >= 0 and col - i == prevQ:
                return False
            if col + i < n and col + i == prevQ:
                return False
            i += 1
        return True
