/*
Runtime: 8 ms, faster than 12.57% of Java online submissions for H-Index.
Memory Usage: 37.3 MB, less than 0.91% of Java online submissions for H-Index.
grandyang idea, shaun java code


*/
class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        Integer[] Arr = new Integer[n];
        for (int i = 0; i < n; ++i) Arr[i] = citations[i];
        
        Arrays.sort(Arr, new Comparator<Integer>(){
            public int compare(Integer a, Integer b) {
                return b - a;
            }
        });
        
        for (int i = 0; i < n; ++i) {
            if (i >= Arr[i]) return i;
            
        }
        return n;
    }
}
