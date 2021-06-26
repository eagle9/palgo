class TinyUrl2 {
private:
    int cnt;
    map<string,string> s2l, l2s;
    const char charset[64] = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
    const string tinyUrl = "http://tiny.url/";
    string newShortUrl() {
        string res = "";
        for (int i = 0, j = cnt; i < 6; i++, j /= 62)
            res += charset[j % 62];
        cnt++;
        return tinyUrl + res;
    }
public:
    TinyUrl2(): cnt(0) {}
    /*
     * @param long_url: a long url
     * @param key: a short key
     * @return: a short url starts with http://tiny.url/
     */
    string createCustom(string &long_url, string &key) {
        string short_url = tinyUrl + key;
        if (l2s.find(long_url) != l2s.end()) {
            if (l2s[long_url] == short_url)
                return short_url;
            return "error";
        }
        if (s2l.find(short_url) != s2l.end()) 
            return "error";
        l2s[long_url] = short_url;
        s2l[short_url] = long_url;
        return short_url;
    }

    /*
     * @param long_url: a long url
     * @return: a short url starts with http://tiny.url/
     */
    string longToShort(string &long_url) {
        if (l2s.find(long_url) != l2s.end())
            return l2s[long_url];
        string short_url = newShortUrl(); 
        l2s[long_url] = short_url;
        s2l[short_url] = long_url;
        return short_url; 
    }

    /*
     * @param short_url: a short url starts with http://tiny.url/
     * @return: a long url
     */
    string shortToLong(string &short_url) {
        if (s2l.find(short_url) != s2l.end())
            return s2l[short_url];
        return "error";
    }
};
