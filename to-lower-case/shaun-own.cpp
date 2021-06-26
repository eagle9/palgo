//shaun own idea and code, accepted first sub
//faster than 60% before use reserve
//runtime 0ms, faster than 100%, mem less than 89%
class Solution {
public:
    string toLowerCase(string str) {
        string res;
        res.reserve(str.length());
        for (char c: str) {
            if ( c >= 'A' && c <= 'Z') res.push_back('a' + c - 'A');
            else res.push_back(c);
        }
        return res;
    }
};
