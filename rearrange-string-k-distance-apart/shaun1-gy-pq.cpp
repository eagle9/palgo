//grandyang idea https://www.cnblogs.com/grandyang/p/5586009.html
//similar to task scheduler idea
//runtime 44ms, faster than 79%, mem less than 53%
class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) return str; //at least 1 apart
        string res;
        int len = str.size();
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq; //char with max count first 
        for (auto a : str) ++m[a];
        /*
        for (auto it = m.begin(); it != m.end(); ++it) {
            q.push({it->second, it->first});
        }*/
        
        for (auto p: m) pq.push(make_pair(p.second, p.first));
        while (!pq.empty()) {
            vector<pair<int, char>> v;
            int cnt = min(k, len);
            for (int i = 0; i < cnt; ++i) {
                if (pq.empty()) return "";
                auto p = pq.top(); pq.pop();
                //res.push_back(p.second);
                res += p.second;
                if (--p.first > 0) v.push_back(p);
                
                //if (--p.first > 0) pq.push(p); --- wrong, you can not push right back in, wait for the group is done
                --len;
            }
            for (auto a : v) pq.push(a);
        }
        return res;
    }
};
