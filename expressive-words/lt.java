
/*
lt running length encoding
1 3 2 3
h e l o
1 1 2 1
h e l o

*/
class Solution {
    public int expressiveWords(String S, String[] words) {
        RLE R = new RLE(S);
        int ans = 0;

        for (String word: words) {
            RLE R2 = new RLE(word);
            if (!R.key.equals(R2.key)) continue;
            boolean flag = true;
            for (int i = 0; i < R.counts.size(); ++i) {
                int c1 = R.counts.get(i);
                int c2 = R2.counts.get(i);
                //c2 > c1 -- already more than what S has
                //c1 < 3 and c1 != c2, can not
                if (c1 < 3 && c1 != c2 || c1 < c2) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans++;
        }
        return ans;
    }
}

class RLE {
    String key;
    List<Integer> counts;

    public RLE(String S) {
        StringBuilder sb = new StringBuilder();
        counts = new ArrayList();

        char[] ca = S.toCharArray();
        int N = ca.length;
        int prev = -1;
        for (int i = 0; i < N; ++i) {
            if (i == N-1 || ca[i] != ca[i+1]) {
                sb.append(ca[i]);
                counts.add(i - prev);
                prev = i;
            }
        }

        key = sb.toString();
    }
}
