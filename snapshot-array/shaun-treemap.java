/*

https://www.cnblogs.com/lz87/p/11314526.html
shaun idea also with bucket, using treemap to organize/order the value changes for a givne key
Runtime: 42 ms, faster than 36.91% of Java online submissions for Snapshot Array.
Memory Usage: 87.1 MB, less than 100.00% of Java online submissions for Snapshot Array.
*/
class SnapshotArray {

    private TreeMap<Integer, Integer>[] snapMap;
    private int snapId = 0;
    public SnapshotArray(int length) {
        snapMap = new TreeMap[length];
        for (int i = 0; i < length; i++) {
            snapMap[i] = new TreeMap<Integer, Integer>();
            snapMap[i].put(0, 0);
        }
    }

    public void set(int index, int val) {
        Map.Entry<Integer, Integer> lastEntry = snapMap[index].lastEntry();
        if(val != lastEntry.getValue()) {
            snapMap[index].put(snapId, val);
        }        
    }

    public int snap() {
        return snapId++;
    }

    public int get(int index, int snap_id) {
        //floor of given snap_id <= given id
        return snapMap[index].floorEntry(snap_id).getValue();
    }
}

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray obj = new SnapshotArray(length);
 * obj.set(index,val);
 * int param_2 = obj.snap();
 * int param_3 = obj.get(index,snap_id);
 */
