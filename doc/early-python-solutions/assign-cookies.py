'''
O(nlogn) time and O(1) space
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor gi, which is the minimum size of a cookie that the child will be content with; and each cookie j has a size sj. If sj >= gi, we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

Note:
You may assume the greed factor is always positive. 
You cannot assign more than one cookie to one child.
'''
class Solution(object):
    def findContentChildren(self, g, s):
        '''
        """
        :type g: List[int] greedy factor
        :type s: List[int] cookie size
        :rtype: int maximal number of content children
        """
        '''
        g.sort()
        s.sort()
        res = 0
        i = 0
        for e in s: #for each cookie
            if i == len(g):
                break
            if e >= g[i]: #content children
                res += 1
                i += 1
        return res
