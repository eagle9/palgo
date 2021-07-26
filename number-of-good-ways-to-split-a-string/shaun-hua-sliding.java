//hua sliding window idea, shaun understood and rewrite
class Solution {
    public int numSplits(String s) {
        int[] l = new int[26];
        int[] r = new int[26];
        int ans = 0;
        int cl = 0;
        int cr = 0;
        for (char c : s.toCharArray()) {
          if (r[c - 'a'] == 0) ++cr;
          r[c - 'a']++;
        }
        for (char c : s.toCharArray()) {
            //add c to left part, cl will be distinct count of c
            l[c - 'a']++;
          if (l[c - 'a'] == 1)  {
              ++cl;
          }
          
            //at the same time, remove c from right part
             r[c - 'a']--;
          if (r[c - 'a'] == 0) {
              --cr;
          }
         
          if (cl == cr) ans++;
        }
        return ans;

    }
}
