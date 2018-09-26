#adapted from jiadai c++ Your submission beats 100.00% Submissions!
class Solution:
    """
    @param candidates: A list of integers
    @param target: An integer
    @return: A list of lists of integers
    """
    def combinationSum(self,candidates, target):
        #write your code here
        result = []
        if len(candidates) == 0 or target <= 0:
            return result
        
        #candidates = list(set(candidates))
        
        prev = 0
        for i in range(1,len(candidates)):
            if candidates[i] != candidates[prev]:
                prev += 1
                candidates[prev] = candidates[i]
        
        candidates = candidates[:prev+1]
        
        candidates.sort()
        valuelist = []
        Solution.result = []
        self.dfs(candidates, 0, target, valuelist)
        return Solution.result
    def dfs(self,candidates, start, target, valuelist):
        if target == 0:
            Solution.result.append(valuelist)
            return

        for i in range(start,len(candidates)):
            if candidates[i] <= target:
                self.dfs(candidates, i, target - candidates[i], valuelist+[candidates[i]])
                
            else:
                break
