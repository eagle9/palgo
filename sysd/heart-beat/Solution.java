//jz java code, simulate Master's dealing with heart beats from slaves
public class HeartBeat {

    public Map<String, Integer> slaves_ip_list; //ip address to timestamp in seconds
    public int k;

    public HeartBeat() {
        // initialize your data structure here
        slaves_ip_list = new HashMap<String, Integer>();
    }

    // @param slaves_ip_list a list of slaves'ip addresses
    // @param k an integer
    // @return void
    public void initialize(List<String> slaves_ip_list, int k) {
        this.k = k;
        for (String ip : slaves_ip_list)
            this.slaves_ip_list.put(ip, 0);
    }

    // @param timestamp current timestamp in seconds
    // @param slave_ip the ip address of the slave server
    // @return nothing
    public void ping(int timestamp, String slave_ip) {
        // Write your code here
        if (!slaves_ip_list.containsKey(slave_ip))
            return;
        
        slaves_ip_list.put(slave_ip, timestamp); //simulate a heart beat message from the slave
    }

    // @param timestamp current timestamp in seconds
    // @return a list of slaves'ip addresses that died
    public List<String> getDiedSlaves(int timestamp) {
        List<String> results = new ArrayList<String>(); //list of slave ip addresses
        
        Iterator iter = slaves_ip_list.entrySet().iterator();
        while (iter.hasNext()) {
            Map.Entry entry = (Map.Entry)iter.next();
            String ip = (String) entry.getKey();
            int time = (Integer) entry.getValue();
            if (time <= timestamp - 2 * k) //2k seconds ago before current timestamp
                results.add(ip);
        }
        return results;
    }
}
