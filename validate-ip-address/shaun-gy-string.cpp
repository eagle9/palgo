/*
cutting: look for invalid, details, implementations
if find ., then check valid ipv4
if find :, then check valid ipv6

grandyang idea, shaun quick read and understand, rewrite

runtime 0ms, faster than 100%, mem less than 57%
*/
class Solution {
public:
    string validIPAddress(string IP) {
        istringstream is(IP);
        string token = "";
        int cnt = 0;
        if (IP.find('.') != string::npos) { // Check IPv4
            while (getline(is, token, '.')) {
                ++cnt;
                //invalid when cnt>4, or token empty, or leading 0 when token.size > 1, or token has more than 3 chars
                if (cnt > 4 || token.empty() || (token.size() > 1 && token[0] == '0') || token.size() > 3) return "Neither";
                //each char in the token should be digit, otherwise invalid
                for (char c : token) {
                    if (c < '0' || c > '9') return "Neither";
                }
                //all digits now, should >=0 and <=255
                int val = stoi(token);
                if (val < 0 || val > 255) return "Neither";
            }
            return (cnt == 4 && IP.back() != '.') ? "IPv4" : "Neither";
        } else { // Check IPv6
            while (getline(is, token, ':')) {
                ++cnt;
                if (cnt > 8 || token.empty() || token.size() > 4) return "Neither";
                //invalid: char not digit, and not a-f, and not A-F
                for (char c : token) {
                    //if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return "Neither";
                    if (c >= '0' && c <= '9' || c >= 'a' && c <= 'f'||c >= 'A' && c <= 'F') continue;
                    else return "Neither";
                }
            }
            return (cnt == 8 && IP.back() != ':') ? "IPv6" : "Neither";
        }
    }
};
