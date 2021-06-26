//https://www.youtube.com/watch?v=r0-zx5ejdq0&t=992s 
//this is stack to reduce valid parenthesis, store index into stack to figure out valid substring length

/*idea as above, shaun has understood, and reread again after 3 weeks
0123456789 10 11
()(()))()) (  )
valid () will be cancelled out each other, unmatched ( stays in the stack with index
[6, 9 ] , add 12 [6,9,12], the valid () string will be before 6, between 69, and 9 and end

//less error prone that lt stack idea
//
//runtime 8ms, faster than 93%, mem less than 63%
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> st; //stack to store char index in s
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') st.push_back(i);
            else { //  ==)
                if (st.empty()) st.push_back(i); //no match
                else {
                    //() matched, pop stack, no enter i into stack
                    if (s[st.back()] == '(') st.pop_back(); 
                    else { // no match and pushed to stack
                        st.push_back(i);
                    }
                }
            }
        }
        //why ??? 
        st.push_back(s.size());
        //for (auto x: st) cout << x << endl;
        
        int start = -1, longest = 0;
        for (int i = 0; i < st.size(); ++i) {
            //start ... st[i],    1 23 4 . 4-1-1
            longest = max(st[i] - start-1, longest);
            start = st[i];//update start
        }
        
        return longest; 
    }
};
