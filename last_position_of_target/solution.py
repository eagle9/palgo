class Solution:
    """
    @param nums: An integer array sorted in ascending order
    @param target: An integer
    @return: An integer
    """
    #Your submission beats 81.80% Submissions!
    #based on jiadai's c++ code
    def lastPosition(self, nums, target):
        # write your code here
        n = len(nums)
        if n == 0:
            return -1
        start,end = 0, n-1
        while start + 1 < end:
            mid = (start + end)/2
            if nums[mid] < target:  #second part
                start = mid + 1
            elif nums[mid] == target: #no return yet
                start = mid  #second part including mid
            else: # A[mid] > target, first part
                end = mid-1

        if nums[end] == target:
            return end
        if nums[start] == target:
            return start
        return -1
