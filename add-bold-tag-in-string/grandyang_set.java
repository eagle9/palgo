//grandyang use bold set to store each char index that needs to be bold
//runtime 47ms, faster than 34%
class Solution {
    public String addBoldTag(String s, String[] dict) {
        int n = s.length();
        StringBuilder res = new StringBuilder();
        Set<Integer> bold = new HashSet<>();
        for (String word: dict) {
            int len = word.length();
            for (int i = 0; i <= n-len; i++) { //last index n-len+len-1 = n-1
                if (s.charAt(i) == word.charAt(0) && s.substring(i,i+len).equals(word)) {
                    for (int j = i; j < i+len; j++) bold.add(j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            //first char needed to be bold
            if (bold.contains(i) && !bold.contains(i-1)) res.append("<b>");
            res.append(s.charAt(i));
            //last char that needs to be bold
            if (bold.contains(i) && !bold.contains(i+1)) res.append("</b>");
        }
        return res.toString();
    }
}
/*
//grandyang bold words in string idea, runtime 24ms, faster than 69%
class Solution {
public:
    string addBoldTag(string S, vector<string>& dict) {
        int n = S.size();
        string res = "";
        unordered_set<int> bold;      
        for (string word : dict) {
            int len = word.size();
            for (int i = 0; i <= n - len; ++i) {
                if (S[i] == word[0] && S.substr(i, len) == word) {
                //if ( S.substr(i, len) == word) { //slower
                    for (int j = i; j < i + len; ++j) bold.insert(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (bold.count(i) && !bold.count(i - 1)) res += "<b>";
            res.push_back(S[i]);
            if (bold.count(i) && !bold.count(i + 1)) res += "</b>";
        }
        return res;
    }
};
*/
