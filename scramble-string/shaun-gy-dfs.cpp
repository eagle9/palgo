//naive recursion,  TLE
class Solution1 {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        for(int isep = 1; isep < s1.size(); ++ isep) {
            //seporate s1 as [0,isep - 1],[isep, s1.size() - 1]
            string seg11 = s1.substr(0,isep);
            string seg12 = s1.substr(isep);
            {//see if forward order is ok
                string seg21 = s2.substr(0,isep);
                string seg22 = s2.substr(isep);
                if(isScramble(seg11,seg21) && isScramble(seg12,seg22)) return true;
            }
            {//see if reverse order is ok
                string seg21 = s2.substr(s2.size() - isep);
                string seg22 = s2.substr(0,s2.size() - isep);
                if(isScramble(seg11,seg21) && isScramble(seg12,seg22)) return true;
            }
        }
        return false;
    }
};

//grandyang recursion, 
//runtime 8ms, faster than 77%, mem less than 57%
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        //sorting and compare is key to eliminate many branches, without this, TLE, with it faster than 98%
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        if (str1 != str2) return false; 
        
        for (int i = 1; i < s1.size(); ++i) {
            //s1  broken into len i from 1 to size-1
            //s1: len i, len n-i from i
            //s2: len i, len n-i from i or
            //s2: len n-i, len i
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
            
            s21 = s2.substr(0, s1.size() - i); //len n-i
            s22 = s2.substr(s1.size() - i); //len i
            
            if (isScramble(s11, s22) && isScramble(s12, s21)) return true;
        }
        return false;
    }
};
