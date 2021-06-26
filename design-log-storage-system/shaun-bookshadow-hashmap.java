//http://bookshadow.com/weblog/2017/07/02/leetcode-design-log-storage-system/
//shaun own idea with ordered map, bookshadow convert key based on gra, prefix substring, similar to my idea, kind of my implementation

//runtime 70ms, faster than 91%, mem less than 100%
public class LogSystem {

    private Map<String, Integer> dmap = new HashMap<>();
    //                             0 . 4     10
    private final String[] gras = "Year:Month:Day:Hour:Minute".split(":");
    //end index  2001:mo:da:hh:mm:ss
    //           0   4  7 .10 13 16
    private final int[] ends = {4, 7, 10, 13, 16};
    
    private String getKeyByGra(String timestamp, String gra) {
        for (int i = 0; i < gras.length; i++) {
            if (gra.equals(gras[i])) {
                return timestamp.substring(0, ends[i]);
            }
        }
        return timestamp;
    }
    
    public LogSystem() {
    }
    
    public void put(int id, String timestamp) {
        dmap.put(timestamp, id);
    }
    
    //how about: instead of iterate all keys, start from start key? 
    public List<Integer> retrieve(String s, String e, String gra) {
        //convert all keys with gra
        String sk = getKeyByGra(s, gra);
        String ek = getKeyByGra(e, gra);
        List<Integer> ans = new LinkedList<>();
        for (String key : dmap.keySet()) {
        //for (String key: dmap.tailMap(s).keySet()) {
            String ck = getKeyByGra(key, gra);
            //sk <= ck .                ck <= endk
            if (sk.compareTo(ck) <= 0 && ck.compareTo(ek) <= 0) {
                ans.add(dmap.get(key));
            }
        }
        return ans;
    }

}


/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * List<Integer> param_2 = obj.retrieve(s,e,gra);
 */
