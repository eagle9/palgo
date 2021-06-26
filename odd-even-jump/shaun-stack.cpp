//use of monotonic stack
//runtime 68ms, faster than 99.67%, mem less than 96%
//https://zhanghuimeng.github.io/post/leetcode-975-odd-even-jump/
//idea from above blog, modified, not yet fully understand
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
                int n = A.size();
        int odd[n]; //odd[i] ---  next index j after odd/up jump from i
        int even[n]; //even[i] --- next index j after even/down jump from i
        
        stack<pair<int, int>> s;
        vector<pair<int, int>> indices;
        for (int i = 0; i < n; i++) indices.emplace_back(A[i], i);
        
        //sort, smaller value in front, if equal value, greater index in front
        struct {
            bool operator () (pair<int,int> a, pair<int,int>b) const{
                if (a.first == b.first) return a.second > b.second;
                if (a.first < b.first) return true;
                else return false;
            }
        } Compare1; //Comparison object
        
        sort(indices.begin(), indices.end(), Compare1);
        
        //now value goes up, push Ai and i into stack, pop when see larger i
        for (int i = 0; i < n; i++) {
            //monotonic decreasing stack, larger triggers pop
            while (!s.empty() && indices[i].second > s.top().second) {
                s.pop();
            }
            if (s.empty())
                even[indices[i].second] = -1;
            else
                even[indices[i].second] = s.top().second;
            s.push(indices[i]);
        }
        
        //s = stack<pair<int, int>>();
        while (!s.empty()) s.pop();
        //indices.clear();
        //for (int i = 0; i < n; i++)
            //indices.emplace_back(A[i], i);
        sort(indices.begin(), indices.end());
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && indices[i].second > s.top().second)
                s.pop();
            if (s.empty())
                odd[indices[i].second] = -1;
            else
                odd[indices[i].second] = s.top().second;
            s.push(indices[i]);
        }
        
        
        bool oddjump[n], evenjump[n]; //can reach end with jump starting from i?
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int j = odd[i]; // up jump from i to j,  Aj >= but min
            if (j != -1) oddjump[i] = evenjump[j];
            else oddjump[i] = (i == n-1);
            
            j = even[i];  //down jump from i to j, Aj <= but max
            if (j != -1) evenjump[i] = oddjump[j];
            else evenjump[i] = (i == n-1);
            
            if (oddjump[i]) ans++;
        }
        return ans;
    }
};
