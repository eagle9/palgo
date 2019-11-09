//grandyang idea1, runtime 3ms, faster than 100%
class ZigzagIterator1 {

    public ZigzagIterator1(List<Integer> v1, List<Integer> v2) {
        this.v1 = v1;
        this.v2 = v2;
        i = j = 0;
    }

    public int next() {
        return i <= j ? v1.get(i++) : v2.get(j++);
    }

    public boolean hasNext() {
        if (i >= v1.size()) i = Integer.MAX_VALUE;
        if (j >= v2.size()) j = Integer.MAX_VALUE;
        return i < v1.size() || j < v2.size();
    }
    private List<Integer> v1 = null, v2 = null;
    int i,j;
    
}
//grandyang idea2, to address the follow up with more than two lists
//runtime 6ms, faster than 22%
class ZigzagIterator {
    class Tuple {
        List<Integer> v;
        int cur, end;
        public Tuple(List<Integer> v, int cur, int end) {
            this.v = v;
            this.cur = cur;
            this.end = end;
        }
    }
    private Queue<Tuple> q = new LinkedList<>();
    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        if (!v1.isEmpty()) q.offer(new Tuple(v1,0,v1.size()));
        if (!v2.isEmpty()) q.offer(new Tuple(v2,0,v2.size()));
    }

    public int next() {
        Tuple t = q.poll();
        List<Integer> v = t.v;
        int cur = t.cur, end = t.end;
        if (cur + 1 != end) q.offer(new Tuple(v,cur + 1, end));
        return v.get(cur);
    }
    public boolean hasNext() {
        return !q.isEmpty();
    }
}


/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i = new ZigzagIterator(v1, v2);
 * while (i.hasNext()) v[f()] = i.next();
 */
