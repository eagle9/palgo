//beats 100%, grandyang using bitmap
//T = O(P*len), where P is the number of permutations, len is length of string
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        int cnt = 0; //count of letters
        for (char c : S) {
            if (c > '9') ++cnt;
        }
        int P = 1 << cnt; //number of permutations
        // or cnt bit number range
        
        for (int i = 0; i < P; ++i) {
            int j = 0;
            string word = "";
            for (char c : S) {
                //for jth letter, get its bit, jth bit of i
                if (c > '9') { //is a letter
                    if (((i >> j++) & 1) == 1) {
                        word.push_back(tolower(c));
                    } else {
                        word.push_back(toupper(c));
                    }
                } else {  //not letter
                    word.push_back(c);
                }
            }
            res.push_back(word);
        }
        return res;
    }
};
