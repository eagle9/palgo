'''https://www.sigmainfy.com/blog/leetcode-subset-i-and-ii.html
no recursive, Your submission beats 100.00% Submissions!
Another different angle to remove duplicates is to treat the continues duplicates number S[i] which appears t times as a whole, and this whole thing have 1 + t choices for us, to put 0..t of them into the subsets. This implementation could be integrated into the 3rd approach fro Subsets I discussed previously and the following iterative implementations is accepted by LeetCode OJ to pass both the Subsets I and II problems:
'''
#not yet working
class Solution:
    def subsetsWithDup(self, S):
        S.sort()
        vv = [[]]
        i,cnt = 0, 0
        n = len(S)
        while (i < n):
            cnt = 1
            while (i + cnt < n and S[i] == S[i + cnt]):
                cnt += 1
            for k  in range(len(v) - 1, -1, -1):
                tmp = vv[k]
                for j in range(1, cnt+0):
                    tmp.append(S[i])
                    vv.append(tmp)
            i += cnt
        return vv
