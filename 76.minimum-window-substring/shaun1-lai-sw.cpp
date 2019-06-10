//shaun lai sliding window idea, 
//i had similar idea, but too clumsy and buggy to implement, check shaun-wrong.cpp
//accepted after 1 bug fix
//runtime 20ms, faster than 61.79%, mem less than 66%
//c++ m[c] will always add c to key set with default value, if you want to keep keyset not change, beware 
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        
        unordered_map<char,int> m; //char in t and count we need to match
        for (char ch: t) m[ch]++;
        int left = 0, matchCount = 0;
		int minLen = INT_MAX, index = 0; //index is the start of substring

		for (int right = 0; right < s.size(); ++right) {
			char ch = s[right];
            
            /*  ---- bug1
            int count = 0;
			if (m.find(ch) != m.end()) count = m[ch];
			if (count == 0) continue;
            */
            
            if (m.find(ch) == m.end()) continue; //not a char in T, skip
            
            //now ch is a char in T, need it count times
			int count = m[ch];
			m[ch] = count -1; //update, found 1, need 1 less
			if (count - 1 == 0) matchCount++; //this char found all
            
			while (matchCount == m.size()) { //all chars matched
				//found a valid window, update the window
				if (right - left + 1 < minLen) {
					minLen = right - left + 1;
					index = left;
				}
				//contract left, remove s[left] 
				char chLeft = s[left++];
				if (m.find(chLeft)== m.end()) continue; //skip char not in T
                
                //is a char in T
				int leftCount = m[chLeft]; 
			   	m[chLeft]++; //remove chLest, need 1 more	
				if (leftCount == 0) matchCount--; 
			}
		}
		return minLen == INT_MAX?"":s.substr(index,minLen);
    }
};

