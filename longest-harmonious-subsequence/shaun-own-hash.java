class Solution {
    /*
    Runtime: 63 ms, faster than 10.80% of Java online submissions for Longest Harmonious Subsequence.
Memory Usage: 40.4 MB, less than 94.74% of Java online submissions for Longest Harmonious Subsequence.

*/
    public int findLHS(int[] nums) {
        Map<Integer,Integer> map = new TreeMap<>();
        
        for (int n: nums) {
            int count = map.getOrDefault(n,0);
            map.put(n,count+1);
            
        }
        int [] key = new int[map.size()];
        int [] count = new int[map.size()];
        int i = 0;
        for (Map.Entry<Integer,Integer> entry: map.entrySet()) {
            key[i] = entry.getKey();
            count[i] = entry.getValue();
            i++;
        }
        int longest = 0;
        for (i = 1; i < key.length; i++) {
            if (key[i] == key[i-1] + 1) {
                int len = count[i] + count[i-1];
                if (len > longest) {
                    longest= len;
                }
            }
        }
        return longest;
    }
    
}



class Solution1 {
    /*
    Runtime: 63 ms, faster than 10.80% of Java online submissions for Longest Harmonious Subsequence.
Memory Usage: 40.4 MB, less than 94.74% of Java online submissions for Longest Harmonious Subsequence.

*/
    
    
    public int findLHS(int[] nums) {
        Map<Integer,Integer> map = new TreeMap<>();
        
        for (int n: nums) {
            int count = map.getOrDefault(n,0);
            map.put(n,count+1);
            
        }
        
        boolean firstTime = true;
        int prevKey = 0;
        int longest = 0;
        for (int key: map.keySet()) {
            if (firstTime) {
                firstTime = false;
                prevKey = key;
                continue;
            }
            if (prevKey +1 == key) {
                int len = map.get(prevKey) + map.get(key);
                if (len > longest) {
                    longest = len;
                }
            }
            prevKey = key;
            
        }
        return longest;
    }
}
