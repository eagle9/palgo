"""
class SVNRepo:
    @classmethod
    def isBadVersion(cls, id)
	# Run unit tests to check whether verison `id` is a bad version
        # return true if unit tests passed else false.
You can use SVNRepo.isBadVersion(10) to check whether version 10 is a 
bad version.
"""

#based on jiadai's c++ code
#Your submission beats 95.40% Submissions!
class Solution:
    """
    @param: n: An integer
    @return: An integer which is the first bad version.
    """
    def findFirstBadVersion(self, n):
        # write your code here
        start,end = 1,n
        while start + 1 < end:
            mid = (start + end) / 2
            if SVNRepo.isBadVersion(mid):
                end = mid
            else: #good version
                start = mid
        if SVNRepo.isBadVersion(start):
            return start
        else:
            return end