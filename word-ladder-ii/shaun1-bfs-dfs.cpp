//jz c++ code, shaun modified to bfs and dfs template style
//basic idea is to construct graph with bfs, and find all paths with dfs
//runtime 220ms, faster than 66%, mem less than 45%

class Solution {
public:
    
    vector<vector<string> > findLadders(string start, string end, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(end)) return {}; //problem statement
        
        int len = start.length();
        unordered_map<string, vector<string> > mnext; //for a node string, list of its next nodes
        unordered_map<string, int> vis; //visited, also stores the steps from start
        queue<string> q;
        
        q.push(start);
        vis[start] = 0;
        while (!q.empty()) {        //bfs with q
            string s = q.front(); q.pop();
            if (s == end) break;
            int step = vis[s];
            vector<string> snext; //to store s's next nodes
            for (int i = 0; i < len; i++) {    		//to change each char of s
                string news = s;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == s[i]) continue;
                    news[i] = c;
                    //skip invalid word by dict
                    if (dict.find(news) == dict.end()) continue;
                    
                    if (!vis.count(news)) {//news not yet visited				
                        q.push(news);
                        vis[news] = step + 1;   //update news' steps
                        //snext.push_back(news);
                    }
                    snext.push_back(news); //store news even no matter it is visited or not
                }
            }
            mnext[s] = snext;					//s --> its next nodes
        }
        
        vector<string> path;
        vector<vector<string>> res;
        path.push_back(start);
        dfs(path,res, mnext, vis, start, end);		//开始dfs
        return res;
    }
    //work on the path from start to end
    //graph is map of each node to its next neighbors
    //vis stores the steps from start for each node
    void dfs(vector<string> &path,  vector<vector<string>>& res, unordered_map<string, vector<string> > &mnext,unordered_map<string, int> &vis, string now, string end){
        if ( now== end) {
            res.push_back(path);
            return;
        }
        for (auto nb: mnext[now]) {
            if (vis[nb] != vis[now] + 1) continue;//this is key, mnext stores all neighbors
            path.push_back(nb); //try now -> nb
            dfs(path,res, mnext, vis, nb, end);
            path.pop_back(); //backtrack to now
           
        }
    }
};
