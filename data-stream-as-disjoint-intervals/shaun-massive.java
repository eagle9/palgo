//massive idea, shaun understood
class Interval {
  int start;   int end;
  Interval() { start = 0; end = 0; }
  Interval(int s, int e) { start = s; end = e; }
}
class SummaryRanges {

    /** Initialize your data structure here. */
    TreeMap<Integer, Interval> tree;

    public SummaryRanges() {
        tree = new TreeMap<>();
    }
    
    //this version easier to understand
    public void addNum(int val) {
        Integer prevKey = tree.floorKey(val);
        int thisKey = val;
        Interval thisInt = new Interval(val, val);
        if(prevKey!=null && tree.get(prevKey).end+1 >= val){
            thisKey = tree.get(prevKey).start;
            thisInt.start = Math.min(tree.get(prevKey).start, val);
            thisInt.end = Math.max(tree.get(prevKey).end, val);
        }
      
        Integer nextKey = tree.ceilingKey(val);
        if(nextKey!=null && nextKey-1==val){
            thisInt.end = tree.get(nextKey).end;
            tree.remove(nextKey);
        }
      
        tree.put(thisKey, thisInt);
    }

    public void addNum2(int val) {
        if(tree.containsKey(val)) return;
        //return the greatest key strictly less than to given key, passed as the parameter
        Integer l = tree.lowerKey(val);
        //return least key greater than key, or null if there is no such key
        Integer h = tree.higherKey(val);
        
        //val connects l and h
        if(l != null && h != null && tree.get(l).end + 1 == val && h == val + 1) {
            tree.get(l).end = tree.get(h).end;
            tree.remove(h);
        }
        // interval l +1 covers val
        else if(l != null && tree.get(l).end + 1 >= val) {
            tree.get(l).end = Math.max(tree.get(l).end, val);
        }
        //interval h connects val, val+1 == h
        else if(h != null && h == val + 1) {
            tree.put(val, new Interval(val, tree.get(h).end));
            tree.remove(h);
        }
        else {
            tree.put(val, new Interval(val, val));
        }
    }


    
    public int[][] getIntervals() {
        int [][] res = new int[tree.values().size()][2];
        int i = 0;
        for (Interval v : tree.values()) {
            res[i][0] = v.start;
            res[i][1] = v.end;
            i++;
        }
        return res;
        
    }
}

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * int[][] param_2 = obj.getIntervals();
 */
