class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        #dict key is the number, value is  its index
        dic = {}
        
        for i in range(len(nums)):
            if nums[i] in dic and abs(i - dic[nums[i]]) <= k:
                return True
            dic[nums[i]] = i
        
        return False
    '''
    Complexity:
    O(n) time
    O(n) space
    '''
