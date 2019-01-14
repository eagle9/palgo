//shaun's java code from grandyang idea, runtime = 11ms
//fixed two errors in decode, be really focused and accurate with details
//otherwise all kinds of errors messages popped up
class Codec {
    // Encodes a list of strings to a single string.
    
    public String encode(List<String> strs) {
        
        StringBuilder sb = new StringBuilder();
        for (String str: strs) {
            sb.append(str.length()).append('/').append(str);
        }
        return sb.toString();
    }
    
    // Decodes a single string to a list of strings.
        
    public List<String> decode(String s) {
        List<String> res = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            int iSlash = s.indexOf('/',i);  //key point, search / with a new start each time
            int len = Integer.valueOf(s.substring(i,iSlash));
            //substring start end, last char index is end-1
            res.add(s.substring(iSlash+1,iSlash+len+1));
            i = iSlash + len + 1;
        }
        return res;
    }
}
/*
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto a : strs) {
            res.append(to_string(a.size())).append("/").append(a);
        }
        return res;
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            auto found = s.find("/", i);
            int len = atoi(s.substr(i, found).c_str());
            res.push_back(s.substr(found + 1, len));
            i = found + len + 1;
        }
        return res;
    }
*/

//fishercode, similar to grandyang, runtime = 12ms
public class Codec2 {

        // Encodes a list of strings to a single string.
        public String encode(List<String> strs) {
            StringBuilder sb = new StringBuilder();
            for (String s : strs) {
                sb.append(s.length()).append('/').append(s);
            }
            return sb.toString();
        }

        // Decodes a single string to a list of strings.
        public List<String> decode(String s) {
            List<String> result = new ArrayList<>();
            int i = 0;
            while (i < s.length()) {
                int slash = s.indexOf('/', i);
                int size = Integer.valueOf(s.substring(i, slash));
                result.add(s.substring(slash + 1, slash + 1 + size));
                i = slash + size + 1;
            }
            return result;
        }
    
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(strs));
