/*
grandyang dfs backtracking with trie, shaun deep read and modified
Runtime: 52 ms, faster than 98% of C++ online submissions for Word Search II.
Memory Usage: 31.8 MB, less than 100.00% of C++ online submissions for Word Search II.
march 15 2019

moved int d[][] = {} to private member section, rather allocate inside recursive helper
*/
class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string str;
        TrieNode() : str("") {
            for (auto &a : child) a = NULL;
        }
    };
    struct Trie {
        TrieNode *root;
        Trie() : root(new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) { //from left to right
                int i = a - 'a';
                //p child i NULL, create TrieNode
                if (!p->child[i]) p->child[i] = new TrieNode();
                p = p->child[i]; //from parent to child
            }
            //store the word s at node from s[0] to s[len-1]
            p->str = s;
        }
    };
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()) return res;
        m = board.size(); n = board[0].size();
        vector<vector<bool> > visit(m, vector<bool>(n, false));
        Trie T;
        for (auto &a : words) T.insert(a);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                TrieNode * node = T.root->child[board[i][j] - 'a'];
                if (node) { //char ij in trie, recur
                    helper(board, node, i, j, visit, res);
                }
            }
        }
        return res;
    }
    //p going down the Trie, ij to its neighbor, res store results
    void helper(vector<vector<char> > &board, TrieNode *p, int i, int j, vector<vector<bool> > &visit, vector<string> &res) {
        //go down to a word now
        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear(); //why this???? because not repeat use the word
        }
        
        visit[i][j] = true;
        for (auto &a : d) {
            int ni = i + a[0], nj = j + a[1];
            //neighbor ni,nj in bound, not visited and letter in trie
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visit[ni][nj] && p->child[board[ni][nj] - 'a']) {
                helper(board, p->child[board[ni][nj] - 'a'], ni, nj, visit, res);
            }
        }
        visit[i][j] = false; //backtracking
    }
private:
    int m, n;
    //const int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const vector<vector<int>> d {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //faster than array!!
};

