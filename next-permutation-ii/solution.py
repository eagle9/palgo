#jiadai, Your submission beats 97.89% Submissions!

class Solution:
    '''
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
    '''
    def nextPermutation(self, nums):
        # write your code here
        n = len(nums)
        if (n == 0 or n == 1):
            return

        i = n - 2
        while (i >= 0 and nums[i] >= nums[i + 1]):
            i-=1

        if (i >= 0):
            j = n - 1
            while (j > i and nums[j] <= nums[i]):
                j-=1
            nums[i], nums[j] = nums[j], nums[i]
        i = i+1
        j = n-1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i+=1
            j-=1

