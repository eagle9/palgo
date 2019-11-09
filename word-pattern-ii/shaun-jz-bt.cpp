//jz dfs with backtracking, kind of brute force, shaun deep read and modified
//runtime 212ms, faster than 58%
class Solution {
public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        return match(pattern, 0, str, 0);
    }

private:
    bool match(const string& pattern, int pidx, const string& str, int sidx) {
        //running index reach len both at the same time， empty pattern c to empty sub string
        if (sidx == str.size() && pidx == pattern.size()) {
            return true;
        }
        //one index reaches end, while the other does not
        if (sidx == str.size() || pidx == pattern.size()) {
            return false;
        }
        
        //now to match pattern[pi] to str.substr(si,len) len=1 to ??
        char c = pattern[pidx];
        int max_len = str.size()-sidx;//max len of substr from si
        if (dict.count(c)) {//pattern repeating
            const string& expected = dict[c]; int elen = expected.size();
            //can exp match str.substr(si,len_of_expect)?
            //size_t found = str.substr(sidx).find(expected); //find won't work
            if (elen <= max_len && str.substr(sidx, elen) != expected) { //no match
            //if (elen <= max_len && str.compare(sidx,elen, expected)) {
                return false;
            } else { //exp matches str.substr(si, lene)
                //str.substr(sidx,elen) == expected . <--- dict[c], recur
                //next char of pattern, next start index of str
                return match(pattern, pidx+1, str, sidx+elen);
            }
        }
        //at this point, c is a new pattern
        //look for its match, for all possible str.substr(si,len 1 to max_len)
        for (int l = 1; l <= max_len; ++l) {
            string word = str.substr(sidx, l);
            if (used.count(word)) { //word used for some pattern, skip, try next word
                continue; //skip because c -- word won't be valid match, word already tied to some other pattern char c-> sub, sub->c, refer to word pattern 1
            }
            //try c ---> word matching
            dict[c] = word;
            //used.insert(word); //use set
            used[word] = c;
            //dfs deeper recur assume c - word matched
            if (match(pattern, pidx+1, str, sidx+l)) {
                return true;
            }
            //back from deeper recur, prev recur no match, backtrack
            used.erase(word);
            dict.erase(c);
        }
        //c to word not matched
        return false;
    }
    
private:
    unordered_map<char, string> dict; //mapping from pattern c to str's substr
    //unordered_set<string> used; //mapping from str's subtr to pattern c,simplified to set
    unordered_map<string,char> used; //mapping from str's substr to pattern c
};
