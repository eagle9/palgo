class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
	    #juan ac java translate
	    dict = {}
	    for i in range(len(num)):
	        r = target-num[i]
	        if r in dict: return ( dict[ r ] + 1, i+1)
	        else: dict[num[i]] = i
	    return None     
    
    #my thinking
    def twoSum2(self,array,target):
        
        position0 = {} #position of number starting from 0
        for i in range(len(array)):
            r = target - array[i]
            if r in position0: 
                return ( position0[r], i)
            else: 
                position0[array[i]] = i
        return None
                

num_list = [2,7,3,4]
 
sol = Solution()
print sol.twoSum(num_list,9)   
print sol.twoSum2(num_list,7)

'''
no 167 Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

'''
