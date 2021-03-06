import unittest
class Solution(object):
    def threeSum(self,nums):
        nums.sort()
        res = []
        length = len(nums)
        for i in xrange(0, length - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            target = nums[i] * -1
            left, right = i + 1, length - 1
            while left < right:
                if nums[left] + nums[right] == target: #case 1,=target, found a triplet
                    res.append([nums[i], nums[left], nums[right]])
                    right -= 1
                    left += 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1 #left pointer goes to right
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1 #right pointer goes to left
                elif nums[left] + nums[right] > target: #case 2, >target, looking for smaller number 
                    right -= 1
                else: #case 3, <target, looking for greater number
                    left += 1
        return res
import unittest

class Test(unittest.TestCase):
    def test1(self):
        a = [-1, 0, 1, 2, -1, -4]
        self.assertItemsEqual(Solution().threeSum(a), [ [-1, 0, 1], [-1, -1, 2] ])

if __name__ == '__main__':
    unittest.main()

'''
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
'''
