/*
lt running length encoding
1 3 2 3
h e l o
1 1 2 1
h e l o

runtime 4ms, faster than 98%, mem less than 43%
*/
//class RLE {
//public:
struct RLE {
    string key;
    vector<int> counts;

    RLE(string S) {
        
        int N = S.size();
        int prev = -1;
        for (int i = 0; i < N; ++i) {
            if (i == N-1 || S[i] != S[i+1]) {
                key.push_back(S[i]);
                counts.push_back(i - prev);
                prev = i;
            }
        }

    }
};
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        RLE R(S);
        int ans = 0;

        for (string word: words) {
            RLE R2(word);
            if (R.key != R2.key) continue;
            bool flag = true;
            for (int i = 0; i < R.counts.size(); ++i) {
                int c1 = R.counts[i];
                int c2 = R2.counts[i];
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
};
