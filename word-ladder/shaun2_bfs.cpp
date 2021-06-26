//shaun 2nd round, own idea and code, accepted first sub after fixing some typos, missing return res,  get_next missing 2nd parameter
//runtime 128ms, faster than 58%, mem less than 15%
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());

        if (!wordDict.count(endWord)) return 0;

        //use bfs from beginWord, tracking level
        unordered_set<string> visited;
        queue<string> q({beginWord});
        visited.insert(beginWord);
        int level = 1; 
        while (!q.empty()) {
        	int n = q.size();
        	for (int i = 0; i < n; ++i) {
        		string word = q.front(); q.pop();
        		if (word == endWord) return level;
        		
        		//word not visited, for all next for word
        		for (string new_word: get_next(word, wordDict)) {
        			if (visited.count(new_word)) continue;
        			q.push(new_word);
        			visited.insert(new_word);
        		}
        	}
        	level++;
        }

        //endWord not found
        return 0;
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
