//shaun has sliding window idea, hua has the same idea
//compare two hash table with ==? yes when they are both vectors
//runtime 32ms, faster than 79%, mem less than 53%
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int ns = s.length();
    int np = p.length();
    vector<int> ans;
    vector<int> vp(26, 0);
    vector<int> vs(26, 0);
    for (char c : p) ++vp[c - 'a'];    
    for (int right = 0; right < ns; ++right) {
        ++vs[s[right] - 'a']; //include right into window 
        //remove left edge of window, left = right-np+1?  left of left is right-np, to be removed
        if (right >= np) --vs[s[right - np] - 'a'];       
        //             [left left+1  left+np-1=right] size = np  ==> left = right-np + 1
        //    right-np [right-np+1                       right]
        if (vs == vp) ans.push_back(right + 1 - np);
    }
    return ans;
  }
};
