'''Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.'''
import collections
class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @param {integer} t
    # @return {boolean}
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        if k < 1 or t < 0:
            return False
            
        dic = collections.OrderedDict()
        
        for i in range(len(nums)):
            key = nums[i] / max(1, t)
            
            for m in (key, key - 1, key + 1):
                if m in dic and abs(nums[i] - dic[m]) <= t:
                    return True
                
            dic[key] = nums[i]
            
            if i >= k:
                dic.popitem(last=False)
        return False
