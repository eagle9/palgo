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
                return ( position0[r] + 1, i + 1)
            else: 
                position0[array[i]] = i
        return None
                

nums = [2,7,3,4]
 
c = Solution()
print c.twoSum(nums,9)   
print c.twoSum2(nums,7)