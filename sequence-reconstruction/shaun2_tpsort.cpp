/*shaun's idea and code for the 2nd round 
wrong answer after many subs, sigh, what's up!
main points for the wrong answer failing cases:
1) seqs could contain [2,3,4], more than just a pair of numbers
2) numbers in seqs could be out of [1 .. n] range
3) there could be duplicate sequences in seqs
rough idea with topological sorting is good, but with this problem, the above details have to be treated correctly

key code to get this right: 
  use numbers in org to initialize follow(directed neighbors) and indegree hash map
finally accepted: runtime 232 ms, faster than 30%, mem less than 39% using unordered_map<int,int> indegree
runtime 184ms, faster than 60% using vector<int,int> indegree
*/

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
       
        int n = org.size();
        
        //unordered_map<int,int> indegree;  
        vector<int> indegree(n+1);
        //unordered_map<int,vector<int>> follow; //why vector<int> as neighbor won't work????
        unordered_map<int, unordered_set<int>> follow; //set of nodes that follows the key
        for (int i: org) {
            follow[i] = unordered_set<int>();
            //indegree[i] = 0;
        }
        int count = 0;
        for (vector<int> seq: seqs) {
            count += seq.size();
            for (int i = 0; i < seq.size(); i++) {
                int b = seq[i];
                if ( seq[i] <= 0 || seq[i] > n) return false;
                if (i == 0) continue;
                //i-1 -> i
                int a = seq[i-1];
                if (!follow[a].count(b)) { // avoid duplicated ordering
                    follow[a].insert(b);
                    indegree[b]++;
                }
                
            }
        }
        
        if (count < n ) return false; //why subsequence total len < org, impossible
        
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> res;
        int index = 0;
        while (q.size() == 1) {   //q.size == 1 is key for uniquely reconstruction
            int i = q.front(); q.pop();
            if (i != org[index++]) return false;
            res.push_back(i);
            for (int j: follow[i]) {
                indegree[j]--;
                if (indegree[j] == 0) q.push(j);
            }
        }
        //return index == n;
        
        if (res.size() != org.size()) return false;
        for (int i = 0; i < org.size(); ++i) {
            if (org[i] != res[i]) return false;
        }
        
        return true;
        
    }
};
