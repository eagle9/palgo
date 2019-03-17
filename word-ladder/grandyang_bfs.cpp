/*
Runtime: 180 ms, faster than 55.13% of C++ online submissions for Word Ladder.
Memory Usage: 15.1 MB, less than 100.00% of C++ online submissions for Word Ladder.
grandyang bfs, shaun deep read
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        //endWord not in dict, as problem statement, can not transformed, return 0
        if (wordSet.count(endWord) == 0) return 0;
        //unordered_map<string, int> pathCnt{{{beginWord, 1}}};
        //not obvious to come up this map, 2 purposes: 1)record distance 2) prevent use words that already used
        unordered_map<string,int> pathCnt; 
        pathCnt[beginWord] =1;
        //queue<string> q{{beginWord}};
        queue<string> q; q.push(beginWord);
        while (!q.empty()) {
            string word = q.front(); q.pop();
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word;
                //change 1 letter, 26 possibilities
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newWord[i] = ch;
                    if (wordSet.count(newWord) && newWord == endWord) return pathCnt[word] + 1;
                    //newWord in dict, not == endWord, not yet seen(preventing going back in ladder)
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
