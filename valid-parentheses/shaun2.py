#Runtime: 20 ms, faster than 97.82% of Python3 online submissions for Valid Parentheses.
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c == '(' or c == '[' or c == '{':
                stack.append(c)
            else:
                if len(stack) == 0: return False
                t = stack.pop()
                if  t == '(' and c != ')' \
                or t =='[' and c != ']' \
                or t == '{' and c != '}':
                    return False
        return len(stack) == 0
        
