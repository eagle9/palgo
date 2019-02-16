/*
Runtime: 180 ms, faster than 55.13% of C++ online submissions for Word Ladder.
Memory Usage: 15.1 MB, less than 100.00% of C++ online submissions for Word Ladder.
grandyang bfs
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        unordered_map<string, int> pathCnt{{{beginWord, 1}}};
        queue<string> q{{beginWord}};
        while (!q.empty()) {
            string word = q.front(); q.pop();
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newWord[i] = ch;
                    if (wordSet.count(newWord) && newWord == endWord) return pathCnt[word] + 1;
                    if (wordSet.count(newWord) && !pathCnt.count(newWord)) {
                        q.push(newWord);
                        pathCnt[newWord] = pathCnt[word] + 1;
                    }   
                }
            }
        }
        return 0;
    }
};
