
//shaun's own idea after union find hint, accepted after fixing 2 bugs
//runtime 20ms, faster than 23.60%, mem less than 9%
class Solution {
    Map<Integer,Integer> rank = new HashMap<>(); //number to its rank
    Map<Integer,Integer> parent = new HashMap<>(); //number to its parent number
    boolean UNION(int i, int j) {
        int pi = find(i), pj = find(j);
        if (pi == pj) return false;
        
        if (rank.get(pi) <= rank.get(pj)) {
            parent.put(pi, pj);
            rank.put(pj, rank.getOrDefault(pj,0) + 1);
        }else {
            parent.put(pj,pi);
            rank.put(pi, rank.getOrDefault(pi,0) + 1);
        }
        return true;
    }
    int find(int i) {
        if (i != parent.get(i)) {
            parent.put(i, find(parent.get(i)));
        }
        return parent.get(i);
    }
    public int longestConsecutive(int[] nums) {
        if (nums.length == 0) return 0;
        for (int i: nums) {
            if (!parent.containsKey(i)) {
                parent.put(i, i);
                rank.put(i, 0);
            }
        }
        
        for (Integer i: parent.keySet()) {
            if (parent.containsKey(i-1)) UNION(i, i-1);
            if (parent.containsKey(i+1)) UNION(i, i+1);
        }
        HashMap<Integer,Integer> bucket = new HashMap<>();
        int ans = Integer.MIN_VALUE;
        for (Integer i: parent.keySet()) {
            
            int root = find(i);
            bucket.put(root, bucket.getOrDefault(root, 0)+1);
            ans = Math.max(ans,bucket.get(root));
        }
        return ans;
    }
}


