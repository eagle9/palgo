typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
//shaun's own idea with basic building blocks
//TLE with direct use of permu with is_palin check
//latter optimized with half+mid+reverse(half)
// template permutation used, with adjustment to prevent duplicates
//finally accepted, runtime 4ms, faster than 100%
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vs res;
        unordered_map<char,int> m;
        for (char c: s) m[c]++;
        int count_odd = 0;
        for (auto p: m) {
            if (p.second % 2 == 1) count_odd++;
        }
        if (s.size() % 2 == 0 && count_odd != 0) return res; //no palin permu
        if (s.size() % 2 == 1 && count_odd != 1) return res; //no palin
        
        string half, mid;
        for (auto& p: m) {
            if (p.second % 2 == 1) mid = p.first;
            for (int i =0; i < p.second/2; ++i) half.push_back(p.first);
        }
        
        vb used(half.size());
        vs res1;
        string cur;
        sort(half.begin(), half.end());
        dfs(half,half.size(),used,cur,res1);
        //cout << half << " " << mid << res1.size() << endl;
        for (string& h: res1) {
            string rh = h;
            reverse(rh.begin(),rh.end());
            res.push_back(h + mid + rh);
        }
        return res;
    }
    
private:
    //Permutation P(m,n) template, without duplicates when numbers not unique
    //take n number out of nums for permu
    //used[i] ith number used in the path
    void dfs(string& s, int n,vb& used, string& cur, vs& res) {
        if (cur.size() == n) {
            res.push_back(cur);
            return;
        }	
        for (int i = 0; i < s.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            cur.push_back(s[i]);
            dfs(s,n,used,cur,res);
            cur.pop_back();
            used[i] = false;
            while (i+1 < s.size() && s[i+1] == s[i]) i++; //added sort and this while loop to prevent duplicated permu when char repeats
        }	
    }
};
