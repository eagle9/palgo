/*
https://leetcode.com/articles/find-and-replace-in-string/
runtime 5ms, faster than 99%
Complexity Analysis

Time Complexity: O(NQ)O(NQ), where NN is the length of S, and we have QQ replacement operations. (Our complexity could be faster with a more accurate implementation, but it isn't necessary.)

Space Complexity: O(N)O(N), if we consider targets[i].length <= 100 as a constant bound.
*/
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        int N = S.length();
        int[] match = new int[N];
        Arrays.fill(match, -1); //good api to know, also Arrays.copyOfRange used once

        for (int i = 0; i < indexes.length; ++i) {
            int ix = indexes[i];
            //get substring at indexes[i], ith index, compare to ith source
            String sub = S.substring(ix, ix+sources[i].length());
            if (sub.equals(sources[i]))
                match[ix] = i; //ith index ix  found match with ith source, to be replaced with ith target
        }

        StringBuilder ans = new StringBuilder();
        int ix = 0;
        //iterate S chars from 0 to N-1
        while (ix < N) {
            if (match[ix] >= 0) {
                ans.append(targets[match[ix]]);
                ix += sources[match[ix]].length();
            }else {
                ans.append(S.charAt(ix++));
            }
            
        }
        
        return ans.toString();
    }
}
