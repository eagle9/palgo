//grandyang idea1, encode lenth/str
//shaun modified to my own idea
//runtime 64ms, faster than 38%, mem less than 81%
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto a : strs) {
            res.append(to_string(a.size())).append("/").append(a);
        }
        return res;
    }
    // Decodes a single string to a list of strings.
    //   abc  defg
    //  3/abc4/defg
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int islash = s.find("/", i); //find / after index 
            //int len = atoi(s.substr(i, islash).c_str());
            int len = stoi(s.substr(i,islash-i));
            res.push_back(s.substr(islash + 1, len));
            i = islash + len + 1;
        }
        return res;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
