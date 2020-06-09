class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        '''pairs = []
        for i in range(len(nums)):
            pairs.append( (nums[i], i) )'''
        pairs = [(nums[i],i) for i in range(len(nums))]
        #pairs.sort(key=lambda x: x[0])
	pairs = sorted(pairs,key=lambda x: x[0])
        left,right = 0, len(nums)-1
        while left < right:
            sum2 = pairs[left][0] + pairs[right][0]
            if sum2 == target:
                return pairs[left][1],pairs[right][1]
            elif sum2 < target:
                left+=1
            else:
                right-=1
        return []
