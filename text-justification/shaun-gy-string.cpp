/*
grandyang idea, this is a problem of pure string manipulation, loops and indexes, test implemenation and case analysis skills
shaun read, understand and comment
the hard part is so many if cases, hard to get right without extensive testing
quick read is okay, not too dragged into it and waste time

runtime 0ms, faster than 100%, mem less than 49%
grandyang's code is better than fisherlei
*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int i = 0;
        while (i < words.size()) {
            int j = i, len = 0;
            //how many words can be filled into 1 line
            //from wordi to wordj, the number of separating spaces is j-i
            while (j < words.size() && len + words[j].size() + j - i <= L) {
                len += words[j++].size();
            }
            
            //now fill word i to j-1 into 1 line string out
            string out;
            int space = L - len; //#total number of spaces to put into out
            for (int k = i; k < j; ++k) {
                out += words[k];
                
                //now consider adding separating spaces between words
                if (space > 0) {
                    int sep; //spaces for 1 separation
                    if (j == words.size()) { //last word filled, use all spaces left
                        if (k == j-1) sep = space; 
                        else sep = 1;
                    } else {
                        if (k < j-1) { //number of separators needed from word k to j-1
                            if (space % (j - 1 - k) == 0) sep = space / (j - 1 - k); //average the spaces for each sep if possible
                            else sep = space / (j - 1 - k) + 1; //7 /3->> 3 3 1 
                            
                        } else sep = space; //no separators needed
                    }
                    out.append(sep, ' '); //append sep copies of space
                    space -= sep; //update total number of spaces
                }
            }
            res.push_back(out);
            i = j; //next starting word index updated
        }
        return res;
    }
};

