/*
abc,  target = "abcbc"
           i
target:abcbc
         j
source:abc


shaun idea with greedy to grow longest subseq, check with edward liu
https://www.cnblogs.com/EdwardLiu/p/11619711.html
*/
class Solution {
public:
    int shortestWay(string source, string target) {
        vector<bool> m(26);
        for (char c: source) m[c - 'a'] = true;
        
        //go through target char by char, sync with source to get longest subseq
        
        int res = 1; //bug, res = 0, should be res = 1
        for (int i = 0, j = 0; i < target.size();) {
            if (!m[target[i] - 'a']) return -1;
            
            //target[i] == source[j]
            while (j < source.size() && target[i] != source[j]) ++j;
            //which exit condition? 
            if (j == source.size()) { //done max find subseq
                res++;
                j = 0;
            }else {
                //target[i] == source[j]
                i++;
                j++;
            }
        }
        return res;
    }
};
