#adapted from jiadai c++,Your submission beats 32.07% Submissions!
#Your submission beats 82.61% Submissions!
#not quite fully understand yet
class Solution:
    """
    @param: numCourses: a total of n courses
    @param: prerequisites: a list of prerequisite pairs
    @return: true if can finish all courses or false
    """
    def canFinish(self,numCourses, prerequisites):
        # Write your code here
        #vector<unordered_set<int>> graph(numCourses);
        graph = [set() for i in range(numCourses)]
        for p in prerequisites:
            #graph[p.second].insert(p.first);
            
            graph[p[1]].add(p[0])

        #vector<int> degrees(numCourses)
        degrees = [0 for i in range(numCourses)]
        for g in graph:
            for node in g:
                degrees[node] += 1

        Q = []
        for i in range(numCourses):
            if degrees[i] == 0:
                Q.append(i)

        count = 0
        while Q:
            course = Q.pop(0)
            count += 1
            for node in graph[course]:
                #if (--degrees[node] == 0) {
                degrees[node] -= 1
                if degrees[node] == 0:
                    Q.append(node)

        return count == numCourses
