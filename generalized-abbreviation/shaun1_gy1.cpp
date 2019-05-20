//grandyang bit manipulation/modeling and iteration
//shaun has read and understand
//runtime 72ms, faster than 53.7%, mem less than 99%
class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        
        int n = word.size();
        int N = pow(2,n), k = 0;
        vector<string> res(N);
        for (int i = 0; i < N; ++i) {
            string out = "";
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) ++cnt; //1 bit
                else { //0 bit
                    if (cnt != 0) {
                        //consecutive 1 count
                        out += to_string(cnt);
                        cnt = 0;
                    }
                    out += word[j];
                }
            }
            if (cnt > 0) out += to_string(cnt);
            //res.push_back(out);
            res[k++] = out;
        }
        return res;
    }
};
