class Solution {
    //grandyang idea, shaun translate to java
    //for each s substring from i=0 to ns-np
    // check substring and p are anagrams or not
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> res = new ArrayList<>();
        if (s.length() == 0) return res;
        int ns = s.length(), np = p.length();
        int [] cnt = new int[128];
        for (char c: p.toCharArray())
            cnt[c]++;
        int i = 0;
        while (i <= ns-np) {
            boolean success = true;
            int [] tmp = new int[128];
            for (int k = 0; k < 128; k++)
                tmp[k] = cnt[k];
            
            for (int j = i; j < i + np; ++j) {
                if (--tmp[s.charAt(j)] < 0) {
                    success = false;
                    break;
                }
            }
            if (success) {
                res.add(i); 
            }
            ++i;
        }
        return res;
    }
}
