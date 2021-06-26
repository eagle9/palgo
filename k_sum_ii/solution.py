#adapted from jiadai c++, Your submission beats 88.89% Submissions!
class Solution:
    '''
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer
    '''
    def kSumII(self,A, k, target):
        # write your code here
        result = []
        numbers = []
        A.sort()
        self.dfs(A, 0, k, 0, target, numbers, result)
        return result

    def dfs(self,A, start, k, sum1, target, numbers, result):
        if (k == 0 or start == len(A)):
            if (sum1 == target and k == 0):
                result.append(numbers.copy())
            return
        i = start
        #for (int i = start; i < A.size() && sum + A[i] <= target; ++i)
        while (i < len(A) and sum1 + A[i] <= target):
            numbers.append(A[i]) #try A[i]
            self.dfs(A, i + 1, k - 1, sum1 + A[i], target, numbers, result)
            numbers.pop()
            i+=1
