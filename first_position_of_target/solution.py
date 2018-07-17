class Solution:
    """
    @param nums: The integer array.
    @param target: Target to find.
    @return: The first position of target. Position starts from 0.
    """
    #Your submission beats 97.80% Submissions!
    #based on jiadai zhao's c++ code
    def binarySearch(self, nums, target):
        # write your code here
        n = len(nums)
        if n == 0:
            return -1
        start,end = 0, n-1
        while start + 1 < end:
            mid = (start + end)/2
            if nums[mid] < target:
                start = mid+1  #nums[mid] < target, so mid+1
            else: #nums[mid] >= target
                end = mid
        #now start+1 == end, check start first
        if nums[start] == target:
            return start
        if nums[end] == target:
            return end
        return -1
