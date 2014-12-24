'''
Created on Dec 23, 2014

@author: XY1267
              A
              |    \
              B        C
              | \      |
              D  E -   F
   
python is so concise, rich builtin makes coding consise and easier to remember
use python builtin function set(), set.add(el)
use python list as a stack to store vertex to be visited, list.pop(), list.extend(set1)
  list.extend(list1): Extend the list by appending all the items in the given list; equivalent to a[len(a):] = L.
           
'''

graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}
def dfs(graph, start):
    visited, stack = set(), [start]
    while stack:
        #list.pop() removes and returns the last item in the list
        vertex = stack.pop()
        if vertex not in visited:
            print "visiting " + vertex
            visited.add(vertex)
            #add vertex's neighbors if not visited
            stack.extend(graph[vertex] - visited)
    return visited

#recursion, not quite right
def dfs2(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    print "visiting " + start
    for next in graph[start] - visited:
        dfs2(graph, next, visited)
    return visited

#yield return generator
def dfs_paths(graph, start, goal):
    stack = [(start, [start])]
    while stack:
        (vertex, path) = stack.pop()
        for next in graph[vertex] - set(path):
            if next == goal:
                yield path + [next]
            else:
                stack.append((next, path + [next]))

def bfs(graph, start):
    visited, queue = set(), [start]
    while queue:
        vertex = queue.pop(0)
        if vertex not in visited:
            print "visiting " + vertex
            visited.add(vertex)
            queue.extend(graph[vertex] - visited)
    return visited

def bfs_paths(graph, start, goal):
    queue = [(start, [start])]
    while queue:
        (vertex, path) = queue.pop(0)
        for next in graph[vertex] - set(path):
            if next == goal:
                yield path + [next]
            else:
                queue.append((next, path + [next]))
"""
Knowing that the shortest path will be returned first from the BFS path generator method 
we can create a useful method which simply returns the shortest path found or 'None' if no path exists. 
As we are using a generator this in theory should provide similar performance results as just breaking out 
and returning the first matching path in the BFS implementation.
"""
def shortest_path(graph, start, goal):
    try:
        return next(bfs_paths(graph, start, goal))
    except StopIteration:
        return None
    
    
bfs(graph, 'A') # {'B', 'C', 'A', 'F', 'D', 'E'}
list(bfs_paths(graph, 'A', 'F')) # [['A', 'C', 'F'], ['A', 'B', 'E', 'F']]
#create list with generator
#print "path:",list(dfs_paths(graph, 'A', 'F')) # [['A', 'C', 'F'], ['A', 'B', 'E', 'F']]
gen = dfs_paths(graph, 'A', 'F')
print "paths:"
for path in gen:
    print path

visited = dfs(graph, 'C') # {'E', 'D', 'F', 'A', 'C', 'B'}
print visited
visited2 = dfs2(graph, 'A') # {'E', 'D', 'F', 'A', 'C', 'B'}
print visited2