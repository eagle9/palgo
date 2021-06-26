#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;
/*https://github.com/awangdev/LintCode/blob/master/Java/Design%20Search%20Autocomplete%20System.java
//shaun read and understand the idea, details to be studied
//awangdev with trie and priority queue in java
shaun write in c++ with the similar idea, this is my first try in c++, slightly different from awang
initially wrong answer

debug using g++, finally found the c++ bug, inside input function, if node->children[c] == NULL, should = new TrieNode()
bug 2 -- insert function, node->freq[sentence] should += count, not = count

finally accepted
runtime 476ms, faster than 30%, mem less than 28%

cutting: think requirements and storage data structure
store init sentences and times into a trie
store completed sentences (end with #) into the trie

trie node:  children hashmap from char to trie node, bool isEnd, also hashmap freq to store all sentences that start with the prefix and their times. 
once we have the sentence data store and update this way, for each input string, we can get find the corresponding trie node, and get all senteces-times directly, then use a minHeap (keep size <= k) to get top k hot sentences quickly

*/
/*https://github.com/awangdev/LintCode/blob/master/Java/Design%20Search%20Autocomplete%20System.java
//shaun read and understand the idea, details to be studied
//awangdev with trie and priority queue
//runtime 197ms, faster than 93%, mem less than 87%

cutting: think requirements and storage data structure
store init sentences and times into a trie
store completed sentences (end with #) into the trie

trie node:  children hashmap from char to trie node, bool isEnd, also hashmap freq to store all sentences that start with the prefix and their times. 
once we have the sentence data store and update this way, for each input string, we can get find the corresponding trie node, and get all senteces-times directly, then use a minHeap (keep size <= k) to get top k hot sentences quickly

*/

class AutocompleteSystem {
private:
    struct TrieNode {
        unordered_map<char,TrieNode*> children;
        bool isEnd; //a sentence ended at the node
        unordered_map<string,int> freq; //this node corresponds to a word, all sentences that have this word as prefix, each sentence ---> freq count 
        TrieNode() {}
    };
    TrieNode* root = new TrieNode();
    
    
    //trie api insert a sentence with count
    void insert(string sentence, int count) {
        TrieNode* node = root;
        string prefix = "";
        for (char c: sentence) {
            if (node->children[c] == NULL) node->children[c] = new TrieNode();
            prefix.push_back(c);
            node = node->children[c];
            //prefix --- node
            node->freq[sentence] += count; //bug = count, should +=
        }
        //node --- sentence
        node->isEnd = true;
    }
    vector<string> findTopK(string input, int k) {
        //given an input string, find the corresponding trie node
        //its freq map store all sentences-count that start with the input
        TrieNode* node = root;
        vector<string> res;
        for (char c: input) {
            //if (node->children[c] == NULL) return res; //wrong answer bug
            if (node->children[c] == NULL) node->children[c] = new TrieNode();
            node = node->children[c];
        }
        //node ----> input
        auto cmp = [](const pair<string,int>& a, const pair<string,int>& b) {
            if (a.second == b.second) return a.first < b.first; // count tied, samller lexi in front, heap greater lexi at top, to discard
            return a.second > b.second; // greater count in front -- heap samller count at top, smaller to discard
        };
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> minHeap(cmp);
        
        for (auto p: node->freq) {
            if (minHeap.size() < k || p.second >= minHeap.top().second) {
                minHeap.push({p.first, p.second});
            }
            if (minHeap.size() > k) minHeap.pop();
        }
        //now minHeap has the top k hot sentences
        // to convert to vector in order, we need to reverse it
        while (!minHeap.empty()) {
            res.insert(res.begin(), minHeap.top().first);
            minHeap.pop();
        }
        return res;
    }
public:
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        if (sentences.size() != times.size()) return;
        for (int i = 0; i < sentences.size(); ++i) {
            insert(sentences[i], times[i]);
        }
    }
    
    
    string sentence_ = ""; //current input
    vector<string> input(char c) {
        vector<string> res;
        if (c == '#') {
            //sentence input is completed, insert into trie
            insert(sentence_,1);
            sentence_ = "";
            
            return res;
        }else {
            sentence_.push_back(c);
            res = findTopK(sentence_, 3);
        }
        return res;
        
    }
    
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

