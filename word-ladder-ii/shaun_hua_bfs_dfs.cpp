//huahua bfs creating graph, finding all paths with dfs
//runtime 180ms, faster than 70%
//shaun tried to understand, mostly, a few details not quite understood
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());//list to set for quick membership check     
        if (!dict.count(endWord)) return {};//problem statement

        dict.erase(beginWord); //why?
        dict.erase(endWord); //why??
        
        //steps store word -> steps from beginWord
        unordered_map<string, int> steps{{beginWord, 1}}; //double }}
        unordered_map<string, vector<string>> parents;
        queue<string> q{{beginWord}};
        //q.push(beginWord);
        
        int step = 0;        
        bool found = false;
        //found endWord at shortest level/step
        while (!q.empty() && !found) {
            ++step;
            //remove all elements from queue at this step/level
            for (int size = q.size(); size > 0; size--) {
                const string p = q.front(); q.pop();
                string w = p; //copy p to w, w to change, p will be parent
                for (int i = 0; i < w.size(); i++) { //for each letter position
                    const char ch = w[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        if (j == ch) continue;
                        w[i] = j;
                        //new word w is one letter diff
                        if (w == endWord) {
                            parents[w].push_back(p);
                            found = true;
                        } else {
                            // new word w != eneWord, but another transform
                            // with the same number of steps
                            //if (steps.count(w) && step < steps.at(w))
                            //why this? 
                            if (steps.count(w) && step < steps[w])
                                parents[w].push_back(p);
                        }
                        
                        if (dict.count(w) == 0) continue; // can not go to w 
                        dict.erase(w); //to visit w, won't visit it again
                        q.push(w);
                        steps[w] = steps[p] + 1;
                        parents[w].push_back(p);
                    }
                    w[i] = ch; //restore w
                }
            }
        }
        
        vector<vector<string>> res;
        if (found) {
            vector<string> curr{endWord};
            getPaths(endWord, beginWord, parents, curr, res);
        }
        return res;
    }
private:
    //find paths from word to beginWord with parents
    //grow path curr
    void getPaths(const string& word, 
                  const string& beginWord, 
                  const unordered_map<string, vector<string>>& parents,
                  vector<string>& curr,
                  vector<vector<string>>& ans) {        
        
        if (word == beginWord) { //curr path reaches beginWord, curr: end -> beginWord
            //use curr to create new path, copy/clone, since curr will continue change
            ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
            return;
        }
        
        for (const string& p : parents.at(word)) { //accepted
        //for (const string& p: parents[word]) { //error
            curr.push_back(p);// try each parent
            //recur with p, curr
            getPaths(p, beginWord, parents, curr, ans);
            curr.pop_back(); //backtracking
        }        
    }
};
