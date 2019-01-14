//grandyang idea1, runtime 63ms, faster than 31%
class Solution {
    public String addBoldTag(String s, String[] dict) {
        StringBuilder res = new StringBuilder();
        int n = s.length();
        int end = 0; //what is end??  end index of match
        boolean [] bold = new boolean[n];
        //iterate the string chars from 0 to n-1
        for (int i = 0; i < n; i++) {
            //check if each word in dict match s.substring(i,i+len)
            for (String word: dict) {
                int len = word.length();
                if (i + len <= n && s.substring(i,i+len).equals(word)) {
                    end = Math.max(end,i+len);
                }
            }
            bold[i] = end > i;
        }
        
        //go over the string s from 0 to n-1 to transform it
        for (int i = 0; i < n; i++) {
            if (!bold[i]){
                res.append(s.charAt(i));
                continue;
            }
            //substring(i,?) match a word in dict
            int j = i;
            while (j < n && bold[j]) j++; //merge consecutive matches
            //j-1 is the last match
            String sub = s.substring(i,j); //chars from i to j-1
            //add bold tag
            res.append("<b>" + sub + "</b>");
            i = j-1; //next i = j, which is not yet checked, this is key
        }
        return res.toString();
        
    }
}

/*
//grandyang idea1, runtime 100ms, faster than 20%
class Solution {
public:
        string addBoldTag(string s, vector<string>& dict) {
            string res = "";
            int n = s.size(), end = 0;
            vector<bool> bold(n, false);
            for (int i = 0; i < n; ++i) {
                for (string word : dict) {
                    int len = word.size();
                    if (i + len <= n && s.substr(i, len) == word) {
                        end = max(end, i + len);
                    }
                }
                bold[i] = end > i;
            }
            for (int i = 0; i < n; ++i) {
                if (!bold[i]) {
                    res.push_back(s[i]);
                    continue;
                }
                int j = i;
                while (j < n && bold[j]) ++j;
                res += "<b>" + s.substr(i, j - i) + "</b>";
                i = j - 1;
            }
            return res;
        }
};
*/
