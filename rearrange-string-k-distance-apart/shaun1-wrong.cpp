//shaun directly use task scheduler pq idea, wrong answer --- failing "a",2
class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <=0) return s;
        
        unordered_map<char, int> counts;
        for (char ch : s) {
            counts[ch]++;
        }
        priority_queue<pair<int, char>> pq;
        //take the task with max count first
        for (pair<char, int> count : counts) {
            pq.push(make_pair(count.second, count.first));
        }
        
        int cycle = k;
        string res = "";
        while (!pq.empty()) {
            vector<pair<int, char>> group;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    group.push_back(pq.top());
                    pq.pop();   
                }
            }
            if (group.size() < cycle) return "";
            
            //update tasks and their count in pq
            for (auto p : group) {
                res += p.second;
                if (--p.first > 0) {
                    pq.push(p);
                }
            }
            
        }
        return res;
    }
};
