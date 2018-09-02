#adapted from jiadai c++, Your submission beats 99.69% Submissions!
class Solution:
    '''
         * @param num: Given the candidate numbers
         * @param target: Given the target number
         * @return: All the combinations that sum to target
    '''
    def combinationSum2(self,num, target):
        # write your code here
        result = []
        if len(num) == 0 or target <= 0:
            return result
        num.sort()
        numbers = []
        self.dfs(num, 0, target, numbers, result)
        return result
    def dfs(self,num, start, target, numbers, result):
        if target == 0:
            result.append(numbers.copy())
            return

        for i in range(start, len(num)):
            if num[i] <= target:
                if i == start or num[i] != num[i - 1]:
                    numbers.append(num[i])
                    self.dfs(num, i + 1, target - num[i], numbers, result)
                    numbers.pop();
            else:
                break
            
