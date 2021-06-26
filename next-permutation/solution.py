#jiadai Your submission beats 98.80% Submissions!

class Solution:
    '''
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
    '''
    def nextPermutation(self, nums):
        # write your code here
        n = len(nums)
        if n == 0 or n == 1:
            return nums

        i = n - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i-=1

        if i >= 0:
            j = n - 1
            while j > i and nums[j] <= nums[i]:
                j-=1
            nums[i], nums[j] = nums[j], nums[i]

        i = i+1
        j = n-1
        while i < j:
            nums[i],nums[j] = nums[j], nums[i]
            i+=1
            j-=1
        return nums
