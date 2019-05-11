// version 1: Random
import java.util.*;
public class TinyUrl1 {
    private Map<String, String> long2Short;
    private Map<String, String> short2Long;
    
    public TinyUrl1() {
        long2Short = new HashMap<String, String>();
        short2Long = new HashMap<String, String>();
    }
    
    /**
     * @param url a long url
     * @return a short url starts with http://tiny.url/
     */
    public String longToShort(String url) {
        if (long2Short.containsKey(url)) {
            return long2Short.get(url);
        }
        
        while (true) {
            String shortURL = generateShortURL(); //generate random 6-char short url
            if (!short2Long.containsKey(shortURL)) {
                short2Long.put(shortURL, url);
                long2Short.put(url, shortURL);
                return shortURL;
            }
        }
    }

    /**
     * @param url a short url starts with http://tiny.url/
     * @return a long url
     */
    public String shortToLong(String url) {
        if (!short2Long.containsKey(url)) {
            return null;
        }
        
        return short2Long.get(url);
    }
    
    private String generateShortURL() {
        String allowedChars =  //10 digits + 26 lower case chars + 26 upper case chars, total 62
            "0123456789" +
            "abcdefghijklmnopqrstuvwxyz" + 
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
        Random rand = new Random();
        String shortURL = "http://tiny.url/";
        for (int i = 0; i < 6; i++) {
            int index = rand.nextInt(62);
            shortURL += allowedChars.charAt(index); //random pick 1 char out of 62 alphanumberic chars
        }
        
        return shortURL;
    }
	public static void main(String [] args) {
		TinyUrl1 t = new TinyUrl1();
		String longUrl = "http://www.lintcode.com/faq/?id=10";
		String shortUrl = t.longToShort(longUrl);
		System.out.println(longUrl);
		System.out.println(shortUrl);
		longUrl = t.shortToLong(shortUrl);
		System.out.println("back to long:");
		System.out.println(longUrl);
	}
}
