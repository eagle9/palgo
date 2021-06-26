public class Solution {
    /*
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
     //Your submission beats 99.00% Submissions!
     //Your submission beats 88.80% Submissions!
    //based on jiadai c++
    public int searchBigSortedArray(ArrayReader reader, int target) {
        // write your code here
        int i = 1;
        while (reader.get(i-1) < target) {
            i = i << 1;
        }
        int start = i >> 1, end = i-1;
        while (start + 1 < end) {
            int mid = (start + end)>>1;
            if (reader.get(mid) < target) {
                start = mid + 1;
            }else {
                end = mid;
            }
        }
        if (reader.get(start) == target) 
            return start;
        if (reader.get(end) == target) 
            return end;
        return -1;
    }
}
