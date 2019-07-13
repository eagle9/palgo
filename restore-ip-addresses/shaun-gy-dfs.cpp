//grandyang dfs idea
//cutting, take 1-3 char substring from the input string s
//if valid ip address part, then we face the similar problem:
// shorter string remained, 1 less parts to take, growing the candidate ip address string
  //when 0 part needed and the remaining string is empty, return the growing candidate
//runtime 0ms, faster than 100%, mem less than 51%
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restore(s, 4, "", res);
        return res;
    }
    //s: remaining string
    //k: k parts needed
    //out: growing candidate ip address string, with . between parts
    void restore(string s, int k, string out, vector<string> &res) {
        if (k == 0) {
            if (s.empty()) res.push_back(out);
        }
        else {
            //get a park by take substring len 1 to 3 from s0
            for (int len = 1; len <= 3; ++len) {
                //s is long enough to taken substring of len
                if (s.size() >= len && isValid(s.substr(0, len))) {
                    //last part(k==1) does not need to append "."
                    //take the valid substring as part
                    // then k-1 needed, remain string get shorter -- s.substr(len)
                    if (k == 1) restore(s.substr(len), k - 1, out + s.substr(0, len), res);
                    else restore(s.substr(len), k - 1, out + s.substr(0, len) + ".", res);
                }
            }
        }
    }
    bool isValid(string s) {
        //part of ip address:
        // len > 1 and len <=3, or return false if len = 0 or len > 3
        if (s.empty() || s.size() > 3) return false;
        // if start with 0, len can only be 1, or if start with 0, len > 1, return false
        //if (s.size() > 1 && s[0] == '0') return false;
        if (s[0] == '0' && s.size() > 1) return false;
        //int res = atoi(s.c_str()); //use 
        int res = stoi(s);
        //the corresponding number between 0 and 255
        return res <= 255 && res >= 0;
    }
};
