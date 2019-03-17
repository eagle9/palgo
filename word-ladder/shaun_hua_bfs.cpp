//hua bfs idea, shaun deep read and modified.
//runtime 208ms, faster than 46%
class Solution1{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //convert wordlist to wordset for quick word in dict check
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        //problem statement, endWord not in dict, return 0, can not transform
        if (dict.count(endWord) ==0) return 0; 
        // queue for bfs
        queue<string> q; q.push(beginWord);
        int step = 0;
        int len = beginWord.length(); //size()
        unordered_set<string> seen;
        seen.insert(beginWord);
        while (!q.empty()) {
            ++step;
            //inorder for step var to be level, you have to deq all elements
            int n = q.size();
            for (int j = 0; j < n; j++) {
                string w = q.front();q.pop();
                //for each letter w[i] of the word, change it to different letter
                for (int i = 0; i < len; i++) {                
                    char ch = w[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (w[i] == c) continue;
                        
                        string nw = w;
                        nw[i] = c;
                        if (seen.count(nw)) continue;
                        // Found the solution, endWord already in dict
                        if (nw == endWord) return step + 1;
                        // Not in dict, skip it
                        if (dict.count(nw) == 0) continue;
                        // w seen before, Remove new word from dict
                        //dict.erase(nw);
                        // Add new word into queue
                        q.push(nw); 
                        seen.insert(nw);
                    }
                    //w[i] = ch;
                }
            }
        }
        return 0;
        
    }
};

//hua's code in comparison, runtime 84ms, faster than 84%
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());        
        if (!dict.count(endWord)) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int l = beginWord.length();
        int step = 0;
        
        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; size--) {                
                string w = q.front();                
                q.pop();
                for (int i = 0; i < l; i++) {                
                    char ch = w[i];
                    for (char j = 'a'; j <= 'z'; j++) {
                        if (j == ch) continue;
                        w[i] = j;
                        // Found the solution
                        if (w == endWord) return step + 1;
                        // new word Not in dict, skip it
                        if (!dict.count(w)) continue;
                        // new word in dict, but not reach endword
                        //do not use it again, Remove new word from dict
                        dict.erase(w);
                        // Add new word into queue for next level bfs
                        q.push(w);                    
                    }
                    w[i] = ch; //remember to change the word back, will this change queue element? No! q.push(w) creates new element with val w
                }
            }
        }
        //can not return endWord after entire bfs, can not transformed
        return 0;
    }
};

