//hua bidirectional bfs, shaun deep read and modified
//runtime 32ms, faster than 99.83%
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //convert word list to hash set for quick word in dict check
        unordered_set<string> dict(wordList.begin(), wordList.end());
        //endWord not in dict, return 0 according to problem statement, can not reach it
        if (dict.count(endWord) == 0) return 0;
        
        int l = beginWord.length();
        
        //why use set, not queue????, because we want to check if new word in the orther bfs frontier, set is O(1) for membership check. but we can use set as queue, for all e in queue, push some elements into queue; for e in set1, set3.insert(e)  set1 = set3
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
                
        int step = 0;
        
        while (!q1.empty() && !q2.empty()) {
            ++step;
            
            // Always expend the smaller queue first, to balance to meet at the middle
            if (q1.size() > q2.size())
                swap(q1, q2);
                        
            unordered_set<string> q;
            //for all words in q1
            for (string w : q1) {
                //for each letter in word
                for (int i = 0; i < l; i++) {
                    char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        if (j == ch) continue;
                        w[i] = j;
                         
                        //new word in the other bfs frontier
                        if (q2.count(w)) return step + 1;
                        if (dict.count(w) >0) {
                            dict.erase(w); //prevent reuse of seen word
                            q.insert(w);
                        }                      
                        
                    }
                    w[i] = ch; //restore word
                }
            }
            //dequeue and push is now replaced with update q1 with q
            //swap(q, q1);
            q1 = q;
        }
        
        return 0;
    }
};
