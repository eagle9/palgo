//hua dfs backtracking with preprocessing, and pruning
//  to find the shortest, try all word purmutations, be aware of the word1 and word2 overlapping
//  wordi: catg -->wordj: atgcatc  atg is the overlap, so adding wordj after wordi only contributes lenj - overlapij
// donote lenj - overlapij as cost[i][j]
// the cost can be pre-processed
//then permutate all words, cursor type, candidate, depth, result
//shaun read, modify, commented, 
//wrong answer use bit mask to implement used

//use hua's bit mask runtime 860ms, faster than 23%, mem less than 92%
//finally accepted with my own bit mask 
//runtime 1008ms, faster than 9%, mem less than 92%
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {    
        const int n = A.size();
        cost = vector<vector<int>>(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                //cost is appending Aj to Ai, after overlapping, len increase
                cost[i][j] = A[j].length(); //init cost with A[j] length
                // find the overlapping substr, Aj  from start
                // Ai  len - 1 - start+1 = k, start = len -k
                for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k){
                    if (A[j].substr(0, k) == A[i].substr(A[i].size() - k))            
                    cost[i][j] = A[j].length() - k;
                }
            }
        }

        vector<int> path(n);
        //vector<bool> used(n);
        best_len = INT_MAX;
        //dfs(A, 0, used, 0, path);
        int used = 0; //bit mask to indicate work index is used or not
        //word length <=12, critical hint that you can use brutal force dfs
        dfs(A, 0, used, 0, path);
        //path and best_path store the word indexes used in order
        string ans = A[best_path[0]];
        for (int k = 1; k < best_path.size(); ++k) {
            int i = best_path[k - 1];
            int j = best_path[k];
            ans += A[j].substr(A[j].length() - cost[i][j]);
        }
        return ans;
    }
private:
    vector<vector<int>> cost; //cost[i][j]: adding wordj to wordi without overlapping, number of chars 
    vector<int> best_path; //permutation of word index that yields the shortest superstring
    int best_len; //goog coding style prefer _ inside variable name
    //cur is also the index of word to be used so far, growing the permutation
    //int used bitmask to indicate word[i] is used or not
    //void dfs(const vector<string>& A, int depth, vector<bool>& used, int cur_len, vector<int>& path) {
    
    //int& used or int used both are fine
    //used vector<bool>& will result TLE
    void dfs(const vector<string>& A, int cur, int& used, int cur_len, vector<int>& path) {
        if (cur_len >= best_len) return; //pruning
        if (cur == A.size()) { //dfs recursion exit
            best_len = cur_len;
            best_path = path; //copy vector, backtracking not needed
            return;
        }
    
        //permutation template
        for (int i = 0; i < A.size(); ++i) {
            //if (used & (1 << i)) continue; //ith bit from right is set
            if (used & (1 << i)) continue;
            path[cur] = i;
            //used[i] = true;
            used = used | (1 << i);
            //used &= 1 << i; //bug 1, should be | to set 1 bit and not mess with other bits
            //used |= 1 << i; //bug 2,  1<<i use ()
            //used = used | (1 << i);
            //used[i] = true; //TLE
            //add word[i] to grow the permutation
            dfs(A,
                cur + 1, 
                used, 
                //used | (1 << i),
                //cur_len + cost[path[d - 1]][i], //you will start like this, then found d-1 could <0
                cur == 0 ? A[i].length() : cur_len + cost[path[cur - 1]][i], //d-1 index derive the corner case
                path);
            
            //backtracking
            //used[i] = false;
            used = used ^ (1 << i);
            //used = used | (1 << i);  bug 2, wrong way to set used[i] to false
        }
    }
};
