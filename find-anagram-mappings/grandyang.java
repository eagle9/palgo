class Solution {
    //grandyang idea, shaun java code, beats 17%
    public int[] anagramMappings(int[] A, int[] B) {
        int [] res = new int[A.length];
        Map<Integer,Integer> m = new HashMap<>();
        for (int i = 0; i < B.length; ++i) m.put(B[i],i);
        for (int i = 0; i < A.length; i++) res[i] = m.get(A[i]);
        return res;
    }
}
