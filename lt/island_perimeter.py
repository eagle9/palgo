import unittest
class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0
        M,N = len(grid),len(grid[0])
        
        def sum_adjacent(i, j):
            adjacent = (i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)
            res = 0

            for x, y in adjacent:
                if x < 0 or y < 0 or x == M or y == N or grid[x][y] == 0:
                    res += 1
            return res
 
        count = 0
        
        for i in xrange(M):
            for j in xrange(N):
                if grid[i][j] == 1:
                    count += sum_adjacent(i, j)
        return count
class Test(unittest.TestCase):
    def test1(self):
	grid = [[0,1,0,0], [1,1,1,0], [0,1,0,0], [1,1,0,0]]        
	ans = Solution().islandPerimeter(grid)
	self.assertEquals(ans,16)
if __name__ == '__main__':
    unittest.main()
