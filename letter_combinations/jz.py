#Your submission beats 99.40% Submissions!
class Solution:
    def letterCombinations(self, digits):
        result = []

        if digits == None or digits =="":
            return result

        map1 = {}
        map1['0'] = []
        map1['1'] = []
        map1['2'] = ['a', 'b', 'c' ]
        map1['3'] = ['d', 'e', 'f' ]
        map1['4'] = ['g', 'h', 'i' ]
        map1['5'] = ['j', 'k', 'l' ]
        map1['6'] = ['m', 'n', 'o' ]
        map1['7'] = ['p', 'q', 'r', 's' ]
        map1['8'] = ['t', 'u', 'v']
        map1['9'] = ['w', 'x', 'y', 'z' ]

        sb = [];
        self.helper(map1, digits, sb, result)

        return result
        
    def helper(self, map1, digits, sb, result):
        if len(sb) == len(digits):
            result.append(''.join(sb))
            return

        for c in map1[digits[len(sb)]]:
            sb.append(c)
            self.helper(map1, digits, sb, result)
            sb.pop()
