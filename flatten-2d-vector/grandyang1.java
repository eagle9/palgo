//grandyang simple idea using 1d list/vector
//runtime 4ms, faster than 46%
public class Vector2D implements Iterator<Integer> {
    private List<Integer> v = new ArrayList<>();
    private int i = 0;
    public Vector2D(List<List<Integer>> vec2d) {
        for (List<Integer> list: vec2d) {
            for (Integer k: list) {
                v.add(k);
            }
        }
    }

    @Override
    public Integer next() {
        return v.get(i++);
    }

    @Override
    public boolean hasNext() {
        return i < v.size();
    }
}


/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i = new Vector2D(vec2d);
 * while (i.hasNext()) v[f()] = i.next();
 */
