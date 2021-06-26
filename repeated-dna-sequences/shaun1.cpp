//grandyang idea, shaun read and understand
//rolling hash method 
//runtime 36ms, faster than 96%, mem less than 72%
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<int> st;
        unordered_map<char,int> a = {
            {'A',0}, {'G',1}, {'T',2}, {'C',3}
        };
        /*
        a['A'] = 0; //use 2bit encoding is more natural than grandyang's use of ascii coding
        a['G'] = 1;
        a['T'] = 2;
        a['C'] = 3; */
        
        int hash = 0; //rolling hash
        //int mask = 1 << 20 - 1;
        int mask = 0x000fffff;
        
        for (int i = 0; i < 9; ++i) hash = hash << 2 | (a[s[i]] & 3);
        for (int i = 9; i < s.size(); ++i) {
            hash = ((hash<< 2) & mask) | a[s[i]] ;
            //if (st.count(hash)) res.insert(s.substr(i - 9, 10));
            if (st.find(hash) != st.cend()) res.insert(s.substr(i - 9, 10));
            else st.insert(hash);
        }
        return vector<string>(res.begin(), res.end());
    }
};


