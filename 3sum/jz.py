#jz c++ Your submission beats 84.20% Submissions!
#jz c++ -> py, Your submission beats 71.40% Submissions!
class Solution:
    ''' @param numbers : Give an array numbers of n integer
    * @return : Find all unique triplets in the array which gives the sum of zero.'''
    def threeSum(self, nums):
        result = []

        nums.sort()
        for i in range(len(nums)):
            if (i > 0 and nums[i] == nums[i - 1]):
                continue
            # two sum;
            start, end = i + 1, len(nums) - 1
            target = -nums[i]
            while start < end:
                if start > i + 1 and nums[start - 1] == nums[start]:
                    start+=1
                    continue

                if nums[start] + nums[end] < target:
                    start+=1
                elif nums[start] + nums[end] > target:
                    end-=1
                else:
                    triple = [nums[i], nums[start], nums[end]]
                    result.append(triple)
                    start+=1

        return result
