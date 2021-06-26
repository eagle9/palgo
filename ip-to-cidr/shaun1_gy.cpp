//grandyang idea, shaun read and understand
//runtime 0ms, faster than 100%, mem less than 71%
class Solution {
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> res;
        
        long x = ip2long(ip);
        
        while (n > 0) {
            long step = x & -x; //low 1 bit
            while (step > n) step /= 2;
            res.push_back(convert(x, step));
            x += step; //move to higher ip
            n -= step; //remaining number of ips
        }
        return res;
    };
    long ip2long(string ip) {
        istringstream is(ip);
        string token;
        long res = 0;
        while (getline(is, token, '.')) { //std::getline(stringstream, token, separator)
            res = res * 256 + stoi(token);
        }
        return res;
    };
    string convert(long x, int step) {
        return to_string((x >> 24) & 255) + "." + to_string((x >> 16) & 255) + "." + to_string((x >> 8) & 255) + "." + to_string(x & 255) + "/" + to_string(32 - (int)log2(step));
    }
};
