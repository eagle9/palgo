//shaun 2nd round, own idea and code based on 1, first sub wrong answer
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        
        unordered_set<string> wordDict(wordList.begin(), wordList.end());

        if (!wordDict.count(endWord)) return res;

        //use bfs from beginWord, tracking level
        unordered_set<string> visited;
        queue<string> q({beginWord});
        visited.insert(beginWord);
        int level = 1; 
        int shortest = -1;
        vector<string> cur;
        while (!q.empty()) {
        	int n = q.size();
        	for (int i = 0; i < n; ++i) {
        		string word = q.front(); q.pop();
                cur.push_back(word);
                
        		if (word == endWord) {
                    //return level
                    shortest = (shortest == -1)? level: min(level, shortest);
                    res.push_back(cur);
                }
        		else {
                    //word not visited, for all next for word
                    for (string new_word: get_next(word, wordDict)) {
                        if (visited.count(new_word)) continue;
                        q.push(new_word);
                        visited.insert(new_word);
                    }
                }
        	}
        	level++;
            if (shortest > 0 && level > shortest) break;
        }

        
        return res;
    }

private:
	vector<string> get_next(string word, unordered_set<string>& wordDict) {
		vector<string> res;
		for (int i = 0; i < word.size(); ++i) {
			//change word[i] to different char
			for (char c = 'a'; c <= 'z'; ++c) {
				if (c != word[i]) {
					char temp = word[i];
					word[i] = c;
					if (wordDict.count(word)) res.push_back(word);
					word[i] = temp;
				}
			}
		}
        return res;
	}
    
};

