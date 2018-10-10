#jz py version 2 Your submission beats 95.63% Submissions!
#not quite understand
class Solution(object):
    # @param start, a string
    # @param end, a string
    # @param dict1, a set of string
    # @return a list of lists of string
    def findLadders(self, start, end, dict1):
        # Write your code here
        dict1.add(start)
        dict1.add(end)

        def buildPath(path,word):
            if len(preMap[word]) == 0:
                result.append([word] + path)
                return
            path.insert(0,word)
            for w in preMap[word]:
                buildPath(path,w)
            path.pop(0)

        length = len(start)
        preMap = {}
        for word in dict1:
            preMap[word] = []
        result = []
        cur_level = set()
        cur_level.add(start)

        while True:
            pre_level = cur_level
            cur_level = set()
            for word in pre_level:
                dict1.remove(word)
            for word in pre_level:
                for i in range(length):
                    left = word[:i]
                    right = word[i+1:]
                    for c in 'abcdefghijklmnopqrstuvwxyz':
                        if c != word[i]:
                            nextWord = left + c + right
                            if nextWord in dict1:
                                preMap[nextWord].append(word)
                                cur_level.add(nextWord)
            if len(cur_level) == 0:
                return []
            if end in cur_level:
                break
        buildPath([],end)
        return result
