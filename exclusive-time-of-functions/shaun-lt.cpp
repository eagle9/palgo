//runtime 56ms, faster than 17%, mem less than 10%
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        vector<int> res(n);
        if (logs.empty()) return res;
        vector<string> s = split(logs[0], ':');
        int id = stoi(s[0]), ts = stoi(s[2]);
        st.push(id);
        int prev = ts;
        for (int i = 1; i < logs.size(); i++) {
            s = split(logs[i], ':');
            id = stoi(s[0]);
            ts = stoi(s[2]);
            if (s[1] == "start") {
                if (!st.empty())
                    res[st.top()] += ts - prev;
                st.push(id);
                prev = ts;
            }else {
                res[st.top()] += ts - prev + 1;
                st.pop();
                prev = ts +1;
                
            }
        }
        return res;

    }
private:
    vector<string> split (const string &s, char delim) {
        vector<string> result;
        stringstream ss (s);

        string token;
        while (getline (ss, token, delim)) { //getline delim only supports char type
            result.push_back (token);
        }

        return result;
    }

};
