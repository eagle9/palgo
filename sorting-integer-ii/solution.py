class Solution:
    """
    @param A: an integer array
    @return: nothing
    """
    def sortIntegers2(self, A):
        # write your code here
        
        self.quickSort(A,0,len(A)-1)
        
    def quickSort(self,A,start,end):
        if start >= end:
            return
        left = start
        right = end
        pv = A[(left + right)/2]
        while left <= right:
            while (left <= right and A[left] < pv):
                left+=1
            while (left <= right and A[right] > pv):
                right-=1
            if (left <= right): #shaun: now A[left] >= pv and A[right] <= pv
                A[left],A[right] = A[right],A[left]
		#keep going with left and right
                left+=1  
                right-=1
        #left > right now        
        self.quickSort(A,start,right)
        self.quickSort(A,left,end)
