class Solution:
    """
    @param nums: an array of Integer
    @param target: target = nums[index1] + nums[index2]
    @return: [index1 + 1, index2 + 1] (index1 < index2)
    """
    #Your submission beats 81.25% Submissions!
    #based on jiadai c++, T = O(logN)
    def twoSum(self, nums, target):
        # write your code here
        start,end = 0, len(nums) - 1
        while start < end: 
            if nums[start] + nums[end] == target:
                return [start + 1,end + 1]
                
            if nums[start] + nums[end] > target:
                end -= 1 #go smaller
            else:
                start += 1 #go larger
        return [] #either no empty or empty


