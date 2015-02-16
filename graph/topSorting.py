'''
Created on Jan 12, 2015

@author: XY1267
'''
from collections import defaultdict
from itertools import takewhile, count

def sort_topologically(graph):
    levels_by_name = {}
    names_by_level = set()

    def walk_depth_first(name):
        if name in levels_by_name:
            return levels_by_name[name]
        children = graph.get(name, None)
        level = 0 if not children else (1 + max(walk_depth_first(lname) for lname in children))
        levels_by_name[name] = level
        names_by_level[level].add(name)
        return level

    for name in graph:
        walk_depth_first(name)

    return list(takewhile(lambda x: x is not None, (names_by_level.get(i, None) for i in count())))


graph = {
        1: [2, 3],
        2: [4, 5, 6],
        3: [4,6],
        4: [5,6],
        5: [6],
        6: []
    }

print(sort_topologically(graph))
'''
      1
      /\
     / 11
    /    \
   2     12
  /        \
 3         13
'''
graph = {
    1: [2,11],
    2: [3],
    11: [12],
    12: [13]
    }
print(sort_topologically(graph))