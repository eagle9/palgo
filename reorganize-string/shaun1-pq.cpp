//same idea and code from rearrange string k distance apart, k = 2
//runtime 4ms, faster than 93%, mem less than 41%
class Solution {
public:
    string reorganizeString(string S) {
        string res;
        int len = S.size();
        unordered_map<char,int> m; //char to its count
        priority_queue<pair<int, char>> pq; //char with max count first 
        for (auto ch : S) ++m[ch];
        /*
        for (auto it = m.begin(); it != m.end(); ++it) {
            q.push({it->second, it->first});
        }*/
        
        for (auto p: m) pq.push(make_pair(p.second, p.first));
        while (!pq.empty()) {
            vector<pair<int, char>> v;
            int cnt = min(2, len);
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
