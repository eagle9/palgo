/*grandyang 
shaun idea as follows, which is similar to grandyang's
1 is "1"
a loop from 2 to n
   a sub loop go over all digits, count repeated digits from left to right(this is another loop), push_back to_string(count), push_back (digit)
runtime 0ms, faster than 100%, mem less than 84%
*/
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string res = "1"; // corresponds to n==1, or i == 1
        int i = 2;
        while (i <= n) {
            string cur = "";
            for (int j = 0; j < res.size(); ++j) {
                int cnt = 1;
                //count repeated digits
                while (j + 1 < res.size() && res[j] == res[j + 1]) {
                    ++cnt;
                    ++j;
                }
                
                //cur += to_string(cnt) + res[j]; //works too
                cur.push_back(cnt + '0');
                cur.push_back(res[j]);
                
            }
            res = cur;
            i++;
        }
        return res;
    }
};
