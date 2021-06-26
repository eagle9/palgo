//grandyang idea 1, brute force with hash table
//very slow and use a lot of memory
class WordFilter {
public:
    WordFilter(vector<string> words) {
        for (int k = 0; k < words.size(); ++k) {
            for (int i = 0; i <= words[k].size(); ++i) {
                for (int j = 0; j <= words[k].size(); ++j) {
                    string prefix = words[k].substr(0,i);
                    string suffix = words[k].substr(words[k].size()-j);
                    m[prefix + "#" + suffix] = k;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        return (m.count(prefix + "#" + suffix)) ? m[prefix + "#" + suffix] : -1;
    }

private:
    unordered_map<string, int> m;
};
