//massive idea, shaun understood
//this one clean code, recommended
//be clear about floor and ceiling, lower and higher api of treeSet/Map
//treeSet with customized comparator
//treeSet.floor(T t) ==> greatest element that <= given t
//treeSet.ceiling(T t) ==> smallest element that >= given t 
//treeSet.lower(T t) ==> greatest element which is < given t 
//treeSet.higher(T t) ==> least element which is > given t
class Interval {
  int start;   int end;
  Interval() { start = 0; end = 0; }
  Interval(int s, int e) { start = s; end = e; }
}
class SummaryRanges {

    private TreeSet<Interval> intervalSet; 
    
    public SummaryRanges() {
        intervalSet = new TreeSet<Interval>((a,b) -> a.start - b.start);
    }
    
    public void addNum(int val) {
        Interval valInterval = new Interval(val, val);
        Interval floor = intervalSet.floor(valInterval);
        if (floor != null) {
            if (floor.end >= val) {
                return;
            } else if (floor.end + 1 == val) {
                valInterval.start = floor.start;
                intervalSet.remove(floor);
            }
        }
        //use higher that does not == t as it is included in floor
        Interval higher = intervalSet.higher(valInterval);
        if (higher != null && higher.start == val + 1) {
            valInterval.end = higher.end;
            intervalSet.remove(higher);
        }
        intervalSet.add(valInterval);
    }
    
    public int[][] getIntervals() {
        int [][] res = new int[intervalSet.size()][2];
        int i = 0;
        for (Interval v : intervalSet) {
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
