import java.util.*;
class Column {
		 public int key;
		 public String value;
		 public Column(int key, String value) {
				 this.key = key;
				 this.value = value;
		 }
}
//https://blog.csdn.net/jmspan/article/details/51749526 
//shaun read and understand?  yes
//java TreeMap has implemented subMap() which Returns a view of the portion of this map whose keys range from fromKey to toKey.
public class MiniCassandra {
    private Map<String, TreeMap<Integer, String>> map = new HashMap<>();
 
    public MiniCassandra() {
        // initialize your data structure here.
    }
    
    /**
     * @param raw_key a string
     * @param column_start an integer
     * @param column_end an integer
     * @return void
     */
    public void insert(String raw_key, int column_key, String column_value) {
        // Write your code here
        TreeMap<Integer, String> tm = map.get(raw_key);
        if (tm == null) {
            tm = new TreeMap<>();
            map.put(raw_key, tm);
        }
        tm.put(column_key, column_value);
    }
 
    /**
     * @param raw_key a string
     * @param column_start an integer
     * @param column_end an integer
     * @return a list of Columns
     */
    public List<Column> query(String raw_key, int column_start, int column_end) {
        // Write your code here
        List<Column> results = new ArrayList<>();
        TreeMap<Integer, String> tm = map.get(raw_key);
        if (tm == null) return results;
		//subMap(from, fromInclusive, to, toInclusive)
        Map<Integer, String> queried = tm.subMap(column_start, true, column_end, true);
        for(int key : queried.keySet()) {
            results.add(new Column(key, queried.get(key)));
        }
        return results;
    }
	public static void main(String [] args) {
		MiniCassandra db = new MiniCassandra();
		db.insert("google", 1, "haha1111");
		db.insert("google", 2, "fofo2222");
		db.insert("google", 3, "tutu3333");
		List<Column> res = db.query("google", 1, 2);
		for (Column x: res) {
			System.out.println(x.key + "," + x.value);
		}
	}
}
