from heapq import heappush, heappop
class Solution:
    def findRelativeRanks(self,nums):
        pq = []
        for i in range(len(nums)):
            heappush(pq, (-nums[i],i ) ) #max heap, by default min heap

        res = ["" for i in range(len(nums))]
        count = 1
        for i in range(len(nums)):
            #n,j = heappop(pq)
            n,j = pq[0] #top of the heap, min 
            if  count == 1:
                res[ j ]  = "Gold Medal"
                
            elif count == 2:
                res[ j ] = "Silver Medal"
                
            elif  count == 3:
                res[ j ] = "Bronze Medal"
                
            else:
                res[ j ] = str(count)
            count+=1    
            heappop(pq)
        return res

nums = [5,4,3,2,1]
print Solution().findRelativeRanks(nums)
