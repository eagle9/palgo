/*
lt hashcode
Runtime: 9 ms, faster than 45.90% of Java online submissions for Encode and Decode TinyURL.
Memory Usage: 37.5 MB, less than 43.77% of Java online submissions for Encode and Decode TinyURL.
*/
public class Codec {
    Map<Integer, String> map = new HashMap<>();

    public String encode(String longUrl) {
        map.put(longUrl.hashCode(), longUrl);
        return "http://tinyurl.com/" + longUrl.hashCode();
    }

    public String decode(String shortUrl) {
        return map.get(Integer.parseInt(shortUrl.replace("http://tinyurl.com/", "")));
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
