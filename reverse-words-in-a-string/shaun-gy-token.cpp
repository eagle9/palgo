//grandyang stringstream and getline token idea
//shaun got it
//runtime 4ms, faster than 99%, mem less than 14%
class Solution {
public:
    string reverseWords(string s) {
        istringstream is(s); //put input string s into stream
        //stringstream is(s); //put input string s into stream, works too
        string ans= "";
        string token = "";
        //             stream, token, sep char
        while (getline(is, token, ' ')) {
            if (token.empty()) continue; //leading trailing repeating space
            //stream tokens: a b c
            //s:c  b a   --- insert at begin, push early word into tail, hence words reversed
            ans = (ans.empty() ? token : (token + " " + ans));
        }
        return ans;
    }
};

//accepted too, but not as clean as getline token idea
class Solution2 {
public:
    string reverseWords(string s) {
        istringstream is(s);
        string token, ans;
        is >> ans;
        while(is >> token) ans = token + " " + ans;
        if(!ans.empty() && ans[0] == ' ') ans = "";
        return ans;
    }
};
