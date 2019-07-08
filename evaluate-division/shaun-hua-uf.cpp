//hua union find, root is no longer a number, but a pair, first to store node, second to store the ratio. I was wondering how uf can store ratio. just do it
//cuting union find, store the ratio from node/root
//runtime 0ms, faster than 100%, mem less than 91%
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

  // parents["A"] = {"B", 2.0} -> A = 2.0 * B
  // parents["B"] = {"C", 3.0} -> B = 3.0 * C
  unordered_map<string, pair<string, double>> parents;
 
  for (int i = 0; i < equations.size(); ++i) {
    const string& A = equations[i][0];
    const string& B = equations[i][1];
    const double k = values[i];
    if (!parents.count(A) && !parents.count(B)) { //neither A or B is in forest
      parents[A] = {B, k}; //init parents for A
      parents[B] = {B, 1.0}; //init parents for B
    } else if (!parents.count(A)) { //B is in forest
      parents[A] = {B, k};
    } else if (!parents.count(B)) { //A is in forest
      parents[B] = {A, 1.0 / k};
    } else {// both A and B are in forest
        auto& rA = find(A, parents);
        auto& rB = find(B, parents);
        //do union here
        //rA.second = A/rA.first ==> rA.first = A/rA.second
        //rB.second = B/rB.first ==> rB.first = B/rB.second
        
        //rA.first/rB.first = (A/B) * rB.second/rA.second
        parents[rA.first] = {rB.first, k  * rB.second/ rA.second};
    }    
  }
 
  vector<double> ans;
  for (const auto& v2 : queries) {
    const string& X = v2[0];
    const string& Y = v2[1];
    if (!parents.count(X) || !parents.count(Y)) {
      ans.push_back(-1.0);
      continue;
    }
    auto& rX = find(X, parents); // {rX, X / rX}
    auto& rY = find(Y, parents); // {rY, Y / rY}
    if (rX.first != rY.first)
      ans.push_back(-1.0);
    else // X / Y = (X / rX / (Y / rY))
      ans.push_back(rX.second / rY.second);
  }
  return ans;
}
private:
  pair<string, double>& find(const string& C, unordered_map<string, pair<string, double>>& parents) {
    if (C != parents[C].first) {
      const auto& p = find(parents[C].first, parents);
      parents[C].first = p.first;
      parents[C].second *= p.second;
    }
    return parents[C];
  }
};

