class Solution {
    int [] parent;
    int [] rank;//not used
    public int numSimilarGroups(String[] strs) {
        int res = 0, n = strs.length;
        parent = new int[n];
        for (int i = 0; i < n; ++i) parent[i] = i;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!isSimilar(strs[i], strs[j])) continue;
                //i and j similar, union them
                parent[find(j)] = i;//union group j and i
            }
        }
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) ++res;
        }
        return res;
    }
    int find(int i) {
        return (parent[i] == i) ? i : find(parent[i]);
    }
    /*
    an anagram of every other string
    */
    boolean isSimilar(String str1, String str2) {
           for (int i = 0, cnt = 0; i < str1.length(); ++i) {
               if (str1.charAt(i) == str2.charAt(i)) continue;
               //not equal, cnt++, can 
               if (++cnt > 2) return false;
           }
           return true;
       }
}

