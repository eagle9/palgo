#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m1,m2,window; //char to its count
        unordered_map<char,int> mi; //char to its index in S
        for (char c: s) m1[c]++;
        for (char c: t) m2[c]++;
        for (char c: t) {
			cout << c << " count = " << m2[c] << endl;
		}	
        /* 
        for (char c: s) {
            //s can not cover chars in t
            if (m1[c] < m2[c]) return "";
        }
		*/
        
        //asumption, there will always be only one unique min window in s
        int left = 0, right = 0;
        int minLen = INT_MAX;
        string ans = "";
        while (right < s.size()) {
            char c = s[right];
			cout << "processing " << c << " at " << right << endl;
            //cout << left << "," << right << endl;
			//c is not in m2
            if (m2.find(c) == m2.cend()) {
                right++;
                cout << "skip " << c << endl;
                continue;
            }
            if (isValid(m2,window)) {
				string candidate = s.substr(left,right-left);
                if (right - left < minLen) {
                    minLen = right - left;
                    ans = candidate;
                }
				cout << "ans = " << ans <<"candidate="<<candidate<< endl;
            }
            if ( window[c] < m2[c]) { //m2 says that we need c m2[c] times
                //enter c into window
                window[c]++;
                mi[c] = right;
                cout << "enter " << c << " at " << right <<endl;
                
            }else {  //>= m2[c], enough c's in the window
                //erase chars from left to mi[c] from window
                //contract left, left = left2
                int iprev = mi[c];
                int left2 = INT_MAX;
				cout << "window.size=" << window.size() << endl;
                for (auto p: window) {
                    char c2 = p.first;
					cout << "window char =" << c2 << " index="<< mi[c2] << endl;
                    if (mi[c2] <= iprev) {
						cout << "remove c2 =" << c2 << endl;
                        window[c2]--;
                        //if (window[c2] == 0) window.erase(c2);
                    }else {
                        //mi[c2] > iprev
                        left2 = min(left2, mi[c2]);
                    }
                }
                
                left = left2;
                cout << "enter " << c << " after remove its prev" << endl;
                cout << "left = " << left << ",char =" << s[left] << endl;
                window[c]++;
                
            }
            right++;
        }
        
        return ans;
        
    }
private:
    bool isValid(unordered_map<char,int>& m2, unordered_map<char,int>& window){
        for (auto p: m2) {
            char c = p.first;
			cout << "m2 char " << c << m2[c] << "---" << window[c] << endl;
            if (m2[c] != window[c]) return false;
        }
        return true;
    }
};
int main() {
	string S = "ADOBECODEBANC", T = "ABC";
	cout << S <<"," << T << endl;
	Solution sol;
	string ans = sol.minWindow(S,T); 
	cout << ans << endl;
}
