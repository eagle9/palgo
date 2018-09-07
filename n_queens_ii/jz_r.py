#Your submission beats 89.11% Submissions!

class Solution:
    def __init__(self):
        self.sum1 = None
    def totalNQueens(self, n):
        self.sum1 = 0
        usedColumns = [None for i in range(n)]
        self.placeQueen(usedColumns, 0)
        return self.sum1

    def placeQueen(self, usedColumns, row):
        n = len(usedColumns)

        if row == n:
            self.sum1 += 1
            return

        for i in range(n):
            if self.isValid(usedColumns, row, i):
                usedColumns[row] = i
                self.placeQueen(usedColumns, row + 1)

    def isValid(self,usedColumns, row, col):
        for i in range(row):
            if usedColumns[i] == col:
                return False

            if (row - i) == abs(col-usedColumns[i]):
                return False

        return True
                                 
