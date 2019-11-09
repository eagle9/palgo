#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;
/*https://github.com/awangdev/LintCode/blob/master/Java/Design%20Search%20Autocomplete%20System.java
//shaun read and understand the idea, details to be studied
//awangdev with trie and priority queue in java
shaun write in c++ with the similar idea
compile error, runtime error, wrong answer
debug using g++, finally found the c++ bug, inside input function
finally accepted
runtime 324ms, faster than 70%, mem less than 28%

cutting: think requirements and storage data structure
store init sentences and times into a trie
store completed sentences (end with #) into the trie

trie node:  children hashmap from char to trie node, bool isEnd, also hashmap freq to store all sentences that start with the prefix and their times. 
once we have the sentence data store and update this way, for each input string, we can get find the corresponding trie node, and get all senteces-times directly, then use a minHeap (keep size <= k) to get top k hot sentences quickly

*/
struct pCompare {
    bool operator ()(const pair<string,int>& a, const pair<string,int>& b) const {
        if (a.second == b.second) return a.first < b.first; //smaller str in fron, greater str at top, discarded
        return a.second > b.second; //greater count in front, smaller count at top, discarded
    }
};
class AutocompleteSystem {
    struct TrieNode {
        bool isEnd; //a sentence ended at this node
        unordered_map<string, int> freq; //all sentences that start with the prefix, and their count, already stored in the trie node
        unordered_map<char, TrieNode*> children; // Map is more applicable to all chars, not limited to 256 ASCII, you can use array too
        TrieNode() {}
    };
    
    TrieNode* root, *curr;
    string sb;
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        if (sentences.empty() || times.empty() || sentences.size() != times.size()) return;
        reset();
        root = new TrieNode();
        for (int i = 0; i < times.size(); i++) {
            insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> rst;
        if (curr == NULL) curr = root;
        if (c == '#') { // save sentence and reset state
            insert(sb, 1);
            reset();
            return rst;
        }
        
        // Update global variable (curr TrieNode and string buffer); or append new character if not exist.
        sb.push_back(c);
        //current TrieNode that corresponds to sentence input up to c
        if (curr->children[c] == NULL) curr->children[c] = new TrieNode(); //must add this line
        curr = curr->children[c];

        // find top k=3 hot sentences in trie that starts with current input
        rst = findTopK(curr, 3);
        
        return rst;
    }
private:    
     vector<string> findTopK(TrieNode* node, int k) {
        vector<string> rst;
        
        if (node == NULL || node->freq.empty()) return rst;
		//use minHeap, min at the top, top k will remain in the heap
         /*
        auto cmp = [](const pair<string,int>& a, const pair<string,int>& b) {
            if (a.second == b.second) return a.first < b.first; //smaller str in fron, greater str at top, discarded
            return a.second > b.second; //greater count in front, smaller count at top, discarded
        };
        priority_queue<pair<string,int>, vector<pair<string,int>>,decltype(cmp) > minHeap(cmp);
        */
        priority_queue<pair<string,int>, vector<pair<string,int>>,pCompare > minHeap; 
        for (auto entry : node->freq) {
            if (minHeap.size() < k || entry.second >= minHeap.top().second) {
                minHeap.push({entry.first, entry.second});
            }
            if (minHeap.size() > k) minHeap.pop();
        }
        
        //convert the minHeap to list
        while (!minHeap.empty()) {
            rst.insert(rst.begin(), minHeap.top().first);
            minHeap.pop();
        }
        
        return rst;
    }
    
    void reset() {
        curr = NULL;
        sb = "";
    }
    
    void insert(string sentence, int count) {
        if (sentence.empty()) return;
        TrieNode* node = root;
		//for all prefix of the sentence, track all sentences that start with the prefix, with freq HashMap<String,Integer> 
        for (char c : sentence) {
            if (node->children[c] == NULL) node->children[c] = new TrieNode();
            node = node->children[c];
            node->freq[sentence] += count;
        }
        node->isEnd = true; // sentence ended at this end, can set word to node as well, if needed
    }
};


/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */


