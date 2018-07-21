class Solution:
    """
    @param nums: an integer array
    @return: nothing
    """
    #based on jiadai c++, Your submission beats 65.40% Submissions!
    def moveZeroes(self, nums):
        # write your code here
        i = 0
        n = len(nums)
        for j in range(n):
            if nums[j] != 0:
                nums[i],nums[j] = nums[j],nums[i]
                i+=1
