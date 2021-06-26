//grandyang idea, two pointer with hash table, 
//runtime 6ms and faster than 100%
class Solution {
    public int characterReplacement(String s, int k) {
        int res = 0, maxCnt = 0, start = 0;
        int [] counts = new int[26]; //store char count from start to i
        for (int i = 0; i < s.length(); ++i) {
            maxCnt = Math.max(maxCnt, ++counts[s.charAt(i) - 'A']);
            //you can replace k chars
            //from start to i
            while (i - start + 1 - maxCnt > k) {
                --counts[s.charAt(start) - 'A'];
                ++start;
            }
            res = Math.max(res, i - start + 1);
        }
        return res;
    }
}
