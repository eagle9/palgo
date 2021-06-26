/*
https://www.cnblogs.com/EdwardLiu/p/11619711.html
Greedy

Use two pointers, one for source: i, one for target: j. While j scan through target, try to match each char of j in source by moving i. Count how many times i goes through source end.

runtime 1ms, faster than 98%, mem less than 100%
*/
class Solution {
    public int shortestWay(String source, String target) {
        char[] sc = source.toCharArray(), ta = target.toCharArray();
        boolean[] map = new boolean[26];
        for (char c : sc) {
            map[c - 'a'] = true;
        }
        
        int j = 0, res = 1;
        for (int i = 0; i < ta.length; i ++, j ++) {
            if (!map[ta[i] - 'a']) return -1;
            while (j < sc.length && sc[j] != ta[i]) j ++;
            if (j == sc.length) {
                res ++;
                j = -1;
                i --;
            }
        }
        return res;
    }
}
