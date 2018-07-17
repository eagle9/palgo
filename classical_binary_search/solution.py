#shaun 7/16/2018 commented from jiuzhang
#https://www.lintcode.com/problem/classical-binary-search/description
#Your submission beats 47.20% Submissions!
class Solution:
    # @param nums: The integer array
    # @param target: Target number to find
    # @return the first position of target in nums, position start from 0 
    def findPosition1(self, nums, target):
        if len(nums) == 0: #empty array, not found
            return -1
            
        start, end = 0, len(nums) - 1
        while start + 1 < end:  #why start+1? because when loop exit, i want start +1 == end 
            mid = (start + end) / 2
            if nums[mid] < target:
                start = mid
            else:
                end = mid
        #now start +1 == end, start right before end        
        if nums[start] == target:
            return start
        if nums[end] == target:
            return end
	#not found
        return -1
    # @param nums: The integer array
    # @param target: Target number to find
    # @return the first position of target in nums, position start from 0 
    #this version is faster because it returns immediately when nums[mid] == target, and moves start or end faster
    #based on jiadai zhao's code
    #Your submission beats 77.20% Submissions!
    def findPosition2(self, nums, target):
        if len(nums) == 0: #empty array, not found
            return -1
            
        start, end = 0, len(nums) - 1
        while start + 1 < end:  #why start+1? because when loop exit, i want start +1 == end 
            mid = (start + end) / 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                start = mid + 1
            else:
                end = mid -1
        #now start +1 == end, start right before end        
        if nums[start] == target:
            return start
        if nums[end] == target:
            return end
	#not found
        return -1
