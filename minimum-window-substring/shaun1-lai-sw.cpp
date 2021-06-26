//shaun lai sliding window idea, 
//i had similar idea, but too clumsy and buggy to implement, check shaun-wrong.cpp
//accepted after 1 bug fix
//runtime 20ms, faster than 61.79%, mem less than 66%
//c++ m[c] will always add c to key set with default value if you declare m[c] even c is not in m yet, if you want to keep keyset not change, beware 
/*
cutting, use hashmap m to count each char in T, 
sliding window expand to right and contract left when valid
matchCnt equal m.size()? , how to update m and matchCnt???

*/
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        
        unordered_map<char,int> m; //char in t and its count we need to match
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
            
            if (m.find(ch) == m.end()) continue; //not a char in T, skip this char, go to next char
            
            //now ch is a char in T, need it count times
			//int count = m[ch];
			//m[ch] = count -1; //update, found 1, need 1 less
			if (--m[ch] == 0) matchCount++; //this char has been fully matched
            
			while (matchCount == m.size()) { //all chars in t are matched
				//found a valid window, update the window
				if (right - left + 1 < minLen) {
					minLen = right - left + 1;
					index = left;
				}
				//contract left edge when the window is valid? if not valid, we want to keep the window wider to have more chars for better chance of being valid  
				char chLeft = s[left++];
				if (m.find(chLeft)== m.end()) continue; //skip char not in T
                
                //is a char in T
				//int leftCount = m[chLeft]; 
			   	//m[chLeft]++; //remove chLest(in T) from the window, now need 1 more	
				if (m[chLeft]++ == 0) matchCount--; 
			}
		}
		return minLen == INT_MAX?"":s.substr(index,minLen);
    }
    
};

