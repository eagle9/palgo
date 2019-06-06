//jz java
/*
同短网址一样, 我们可以用两个哈希表处理长网址和短网址之间的相互映射关系.
我们需要额外处理的便是用户设定的网址与已有的冲突时, 需要返回 "error".
但是注意这个细节: 如果用户设定的和已有的恰好相同, 那么同样应该返回短网址.
*/
public class TinyUrl2 {
    private HashMap<String,String> s2l = new HashMap<String,String>();
    private HashMap<String,String> l2s = new HashMap<String,String>();
    private int cnt = 0; //global id, increment for each new short url created
    private final StringBuffer tinyUrl = new StringBuffer("http://tiny.url/");
    private final String charset = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
    
    private String newShortUrl() {
        StringBuffer res = new StringBuffer();
        for (int i = 0, j = cnt; i < 6; i++, j /= 62)
            res.append(charset.charAt(j % 62));
        cnt++;
        return tinyUrl + res.toString();
    }
    
    /*
     * @param long_url: a long url
     * @param key: a short key
     * @return: a short url starts with http://tiny.url/
     */
    public String createCustom(String long_url, String key) {
        String short_url = tinyUrl + key;
        if (l2s.containsKey(long_url)) {
            if (l2s.get(long_url).equals(short_url))
                return short_url;
            else
                return "error";
        }
        if (s2l.containsKey(short_url))
            return "error";
        l2s.put(long_url, short_url); 
        s2l.put(short_url, long_url);
        return short_url;
    }

    /*
     * @param long_url: a long url
     * @return: a short url starts with http://tiny.url/
     */
    public String longToShort(String long_url) {
        if (l2s.containsKey(long_url))
            return l2s.get(long_url);
        String short_url = newShortUrl(); 
        l2s.put(long_url, short_url); 
        s2l.put(short_url, long_url);
        return short_url; 
    }

    /*
     * @param short_url: a short url starts with http://tiny.url/
     * @return: a long url
     */
    public String shortToLong(String short_url) {
        if (s2l.containsKey(short_url))
            return s2l.get(short_url);
        return "error";
    }
}
