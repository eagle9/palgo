//grandyang naive enumerate time, only 24*60 min a day
//cutting brute naive, loop time min by min, convert time point to string, check if each char of the string in the given time string
//runtime 4ms, faster than 80%, mem less than 45%
class Solution {
public:
    string nextClosestTime(string time) {
        string res = "0000";
        vector<int> v{600, 60, 10, 1};  //each digit is how many multiples of unit? 
        int icomma = time.find(":");
        //      ic
        // hh   :    mm    
        
        int cur = stoi(time.substr(0, icomma)) * 60 + stoi(time.substr(icomma + 1));
        
        for (int i = 1, d = 0; i <= 1440; ++i) { //1440 = 24 * 60
            int next = (cur + i) % 1440;
            //convert int time to 4 chars
            for (d = 0; d < 4; ++d) { 
                // h            h    :      m          m
                // 600 min     60min       60min     600min
                //from right char0     char1        char2     char3
                res[d] = '0' + next / v[d];
                
                next %= v[d]; //done high digit, remove big units
                //if res[d] not in given time string, try next time point
                if (time.find(res[d]) == string::npos) break;
            }
            //found all digits in given time, exit for i loop
            if (d >= 4) break;
        }
        return res.substr(0, 2) + ":" + res.substr(2);
    }
};
