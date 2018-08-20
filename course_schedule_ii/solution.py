#adapted from jiadai c++ Your submission beats 58.50% Submissions!
class Solution:
    """
    @param: numCourses: a total of n courses
    @param: prerequisites: a list of prerequisite pairs
    @return: the course order
    """
    def findOrder(self, numCourses, prerequisites):
        # write your code here
        #vector<unordered_set<int>> graph(numCourses);
        graph = [set() for i in range(numCourses)]
        for p in prerequisites: # [i,j]   i <---j
            graph[p[1]].add(p[0])   #for i in graph, its set stores all j <--- i

        #vector<int> degrees(numCourses);
        degrees = [0 for i in range(numCourses)]  #in degree
        for set1 in graph:
            for node in set1:
                degrees[node] += 1

        #queue<int> Q;
        Q = []
        for i in range(numCourses):
            if degrees[i] == 0:
                Q.append(i)

        count = 0
        #vector<int> result(numCourses);
        result = [None for i in range(numCourses)]
        while Q:
            course = Q.pop(0)
            result[count] = course
            count+=1
            for node in graph[course]:
                degrees[node] -= 1
                if degrees[node] == 0:
                    Q.append(node)

        if count != numCourses:
            return []

        return result
