class Solution:
    """
    @param A: an integer array
    @param target: An integer
    @param k: An integer
    @return: an integer array
    """
    #based on jiadai c++, Your submission beats 97.60% Submissions!

    def kClosestNumbers(self, A, target, k):
        # write your code here
        n = len(A)
        if n == 0:
            return []
        start,end = 0, n-1
        while start + 1 < end:
            mid = (start + end)/2
            if A[mid] >= target:  #in first half
                end = mid
            else: # A[mid] < target, in second half
                start = mid + 1
                
        #loop ends, start+1 == end now, (start,end) are closest 
        #determine a start pos index to look for k numbers
        # hopefully A[index] >= target, otherwise  end+1 cause greater
        index = None
        if A[start] >= target:
            index = start
        elif A[end] >= target:
            index = end
        else: #target > A[start] and target > A[end]
            index = end + 1

        left,right = index-1, index
        result = []
        #look for k numbers from 2 directions: left and right
        for i in range(k):
            if right >= n: #done with right, take left
                result.append(A[left])
                left -= 1
            elif left < 0: #done with left, take right
                result.append(A[right])
                right += 1
            elif target - A[left] <= A[right] - target: #left side closer
                result.append(A[left])
                left-=1
            else: #right side closer
                result.append(A[right])
                right += 1
        return result
