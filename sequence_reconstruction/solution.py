#adapt from jz java,Your submission beats 44.91% Submissions!
#initially not quite understand java, after translate to python, understand better
#basically it is to check if topological sorting is unique or not
#adapt from jz java,Your submission beats 44.91% Submissions!
class Solution:
    """
    @param org: a permutation of the integers from 1 to n
    @param seqs: a list of sequences
    @return: true if it can be reconstructed only one or false
    """
    
    def sequenceReconstruction(self,org, seqs):
        #Write your code here
        #Map<Integer, Set<Integer>> map = new HashMap<Integer, Set<Integer>>();
        map1 = {} #integer-> set
        #Map<Integer, Integer> indegree = new HashMap<Integer, Integer>();
        indegree = {} #integer->integer

        for num in org:
            map1[num] = set()
            indegree[num] = 0

        n = len(org)
        count = 0
        for seq in seqs:
            count += len(seq)
            if len(seq) >= 1 and (seq[0] <= 0 or seq[0] > n):
                return False
            for i in range(1,len(seq)):
                if seq[i] <= 0 or seq[i] > n: #any outbound number in seq, of course return False
                    return False
                #if (map.get(seq[i - 1]).add(seq[i]))# java set.add returns true if not in
                if seq[i] not in map1[seq[i - 1]]:
                    map1[ seq[i-1] ].add(seq[i])  #map of sets, each set store i which has prev
                    indegree[seq[i]] += 1
               # case: [1], []
        if count < n: #of course, no way you can construct org with seqs, short of it
            return False

        Q = []
        for key in indegree:
            if indegree[key] == 0:
                Q.append(key)

        cnt = 0
        while len(Q) == 1: #why not while Q is not empty? because the uniqueness requirement
            #ele = q.poll(); #java deque poll Retrieves and removes the head of this queue,
            ele = Q.pop(0)
            
            for next1 in map1[ele]: #next1 are all i which has ele as prev, take ele will reduce its neighbors's indegree
                indegree[next1] -= 1
                if indegree[next1] == 0:
                    Q.append(next1);
            if ele != org[cnt]:  #what's this? different, of course return False, org is given input
                return False
            cnt+=1

        return cnt == len(org) # if can be reconstructed, then cnt must be equal to len(org)
