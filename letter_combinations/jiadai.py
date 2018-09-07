#jiadai c++ Your submission beats 99.40% Submissions!
class Solution:
    '''
     * @param digits: A digital string
     * @return: all posible letter combinations
    '''
    def letterCombinations(self, digits):
        #write your code here
        result = []
        if  len(digits) == 0:
            return result

        dict1 = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        self.dfs(digits, 0, "", dict1, result)
        return result

    def dfs(self, digits, start, path, dict1, result):
        if start == len(digits):
            result.append(path)
            return

        for c in dict1[ord(digits[start]) - ord('0')]:
            self.dfs(digits, start + 1, path + c, dict1, result)
