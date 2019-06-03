//hua's recusion with memo
//shaun understood the idea
//runtime 0ms, faster than 100%, mem less than 7%
class Solution {
public:
    int numDecodings(string s) {
        if (cache.count(s)) return cache[s];
        
        //idea, reduce s in 1 or 2 chars, smaller string, same problem, recursion
        if (s.empty()) return 1;
        //s[0]   s[1..]  split
        if (s[0] == '0') return 0; //start with 0, no decode
        if (s.size() ==1) return 1;
        
        // s[0]  s[1..] split
        int res = numDecodings(s.substr(1));
        
        //s[0..1]  s[2..] split, s[0] s[1] must combine, decode s[0] s[1] separate will result repetitions
        if (s.substr(0,2) <= "26")
            res += numDecodings(s.substr(2));
        return cache[s] = res;
    }
    
private:
    unordered_map<string,int> cache;
};
