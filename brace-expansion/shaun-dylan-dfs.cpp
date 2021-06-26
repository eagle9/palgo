/*
https://www.cnblogs.com/Dylan-Java-NYC/p/11791503.html
shaun similiar idea, but kind of messy with string processing
dylan's dfs is not very to come up, directly use input string S in the dfs
runtime 4ms, faster than 94%, mem less than 60%
*/
class Solution {
public:
    vector<string> expand(string S) {
        vector<string> res;
        string sb;
        dfs(S, 0, sb , res);
        sort(res.begin(), res.end());
        return res;
    }
    
private:
    void dfs(string& s, int i, string& sb, vector<string>& res){
        if(i == s.size()){
            res.push_back(sb);
            return;
        }
        
        if(s[i] == '{'){
            int j = i+1;
            vector<char> cand;
            while(j<s.size() && s[j]!='}'){
                if (s[j] >= 'a' && s[j] <= 'z')  cand.push_back(s[j]);
                j++;
            }
            
            //String [] candidates = s.substring(i+1, j).split(",");
            for(char c : cand){
                sb.push_back(c);
                dfs(s, j+1, sb, res); //j+1 here, move cursor entire {} section
                sb.pop_back();
            }
        }else{
            sb.push_back(s[i]);
            dfs(s, i+1, sb, res);
            sb.pop_back();
        }
    }
};
