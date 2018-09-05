#ling huchong, use bfs, find all subsets level by level
#Your submission beats 99.60% Submissions!

class Solution:

    '''
     * @param nums: A set of numbers
     * @return: A list of lists
    '''
    def subsets(self, nums):
        results = []

        if nums == None:
            return results # empty list

        nums.sort()

        # BFS
        queue = [[]]

        while queue:
            subset = queue.pop(0)
            results.append(subset)

            for i in range(len(nums)):
                if (len(subset) == 0 or subset[-1] < nums[i]):
                    nextSubset = subset.copy()
                    nextSubset.append(nums[i])
                    queue.append(nextSubset)
        return results

