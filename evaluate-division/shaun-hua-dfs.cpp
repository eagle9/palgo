//hua dfs, actually less error prone than gy's bfs
//cutting
//build a graph, then figure out the distance from A to B
//  use A's neibor map, for each neib C, A to C, boils to CB * CA
//runtime 0ms, faster than 100%, mem less than 85%
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // g[A][B] = k -> A / B = k
        unordered_map<string, unordered_map<string, double>> g;        
        for (int i = 0; i < equations.size(); ++i) {
            const string& A = equations[i][0];
            const string& B = equations[i][1];
            const double k = values[i];
            g[A][B] = k;
            g[B][A] = 1.0 / k;
        }
        
        vector<double> ans;
        for (const auto& v2 : queries) {
            const string& X = v2[0];
            const string& Y = v2[1];
            if (!g.count(X) || !g.count(Y)) {
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;  //1 fresh visited set for each dfs call           
            ans.push_back(divide(X, Y, g, visited));
        }
        return ans;
    }
private:
    // get result of A / B, find the distance from A to B
    double divide(const string& A, const string& B, 
                  unordered_map<string, unordered_map<string, double>>& g,
                  unordered_set<string>& visited) {        
        
        if (A == B) return 1.0; //recur base exit
        
        visited.insert(A); //find B from A's neibor map
        for (const auto& pair : g[A]) {
            // neibor map key val pair, 
            const string& C = pair.first;
            double distAC = pair.second;
            if (visited.count(C)) continue;
            
            //A to B,  boils down C to B
            double distCB = divide(C, B, g, visited); // distCB = C / B
            
            //if (distCB > 0) return distCB * g[A][C]; //hua code
            if (distCB > 0) return distAC * distCB; //shaun code
        }
        //could not find a path via A's neibor map
        return -1.0;
    }
};
