//jz, beats 86.20%
//now i understand
//map machine id to multiple points along the ring
//  map keys to the same ring
//    for a key, find the first shard(vnode) >= the hash of key, then the key is stored in the machine associated with the shard(vnode)
public class Solution {
    //n is the number of intervals along the ring
    public int n;
    //k is the number of shards that a machie is responsible
    public int k; 
    public Set<Integer> ids = null; //set of shard ids
    public Map<Integer, List<Integer>> machines = null; //machine id to its shard id list

    // @param n a positive integer
    // @param k a positive integer
    // @return a Solution object
    public static Solution create(int n, int k) {
        // Write your code here
        Solution solution = new Solution();
        solution.n = n;
        solution.k = k;
        solution.ids = new TreeSet<Integer>();
        solution.machines = new HashMap<Integer, List<Integer>>();
        return solution;
    }

    // @param machine_id an integer
    // @return a list of shard ids
    public List<Integer> addMachine(int machine_id) {
        // Write your code here
        Random ra =new Random();
        List<Integer> random_nums = new ArrayList<Integer>();
        for (int i = 0; i < k; ++i) {
            int index = ra.nextInt(n); //random spread point
            while (ids.contains(index))
                index = ra.nextInt(n);
            //ids does not contain index, index is the new shard
            ids.add(index);
            random_nums.add(index);
        }
        //random_nums is the new shard list, k shards
        Collections.sort(random_nums);
        machines.put(machine_id, random_nums);
        return random_nums;
    }

    // @param hashcode an integer
    // @return a machine id
    public int getMachineIdByHashCode(int hashcode) {
        // Write your code here
        int distance = n + 1;
        int machine_id = 0;
        //for (Map.Entry<Integer, List<Integer>> entry : machines.entrySet()) {
		//go over all machine and its shard list
		//find the min shard id >= hashcode
        for (int key: machines.keySet()) {
            //int key = entry.getKey();
            //List<Integer> random_nums = entry.getValue();
            List<Integer> random_nums = machines.get(key);
			//random_nums sorted
            for (Integer num : random_nums) {
                int d = num - hashcode;
                if (d < 0)  //num < hashcode
                    d += n;
                if (d < distance) { //find min distance, hashcode <= num < n+1
                    distance = d;
                    machine_id = key;
                }
            }
        }
        //machine_id has a shard > hashcode and closest to hashcode
        return machine_id;
    }
}
