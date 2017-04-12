class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) == 0:
            return False
        mp = {}
        for num in nums:
            if not mp.get(num):
            if num not in mp:
                mp[num] = True
            else:
                return True
        return False
