//grandyang idea, shaun has read and understood
//runtime 4ms, faster than 95%, mem less than 56%
class Solution {
public:
    string toHex(int num) {
        string res = "";
        //right shift 4bits and mask, for 8 times, 32bit integer
        //if number >> and becomes 0, end loop
        for (int i = 0; num && i < 8; ++i) {
            int t = num & 0xf; //take the lowest 4 bits
            //add char to begining of the res string, lowest bits to tail, 
            if (t >= 10) res = char('a' + t - 10) + res; //convert to a-f for 10-15
            else res = char('0' + t) + res;
            num >>= 4;
        }
        return res.empty() ? "0" : res;
    }
};

