//grandyang idea, beats 99%, not quite understand
//c++ in place, for java if using String, requires extra space, using char[] is okay
//check reverse words in a string iii
class Solution {
public:
    void reverseWords(string &s) {
        //since there are leading, trailing and repeated space, use storeIndex to store valid chars
        int storeIndex = 0, n = s.size();
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') { //non space char
                if (storeIndex != 0) s[storeIndex++] = ' '; //why???
                
                int j = i;
                //inbound non space chars
                while (j < n && s[j] != ' ') s[storeIndex++] = s[j++];
                
                //word len is j - i, okay
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                //
                i = j;
            }
        }
        
        s.resize(storeIndex);
        reverse(s.begin(), s.end());
    }
};
