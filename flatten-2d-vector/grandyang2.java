//grandyang idea2, using just a ref to vec2d and two int variables to iterate, runtime 3ms, faster than 95%
//不直接转换为一维数组，而是维护两个变量x和y，我们将x和y初始化为0，对于hasNext函数，我们检查当前x是否小于总行数，y是否和当前行的列数相同，如果相同，说明要转到下一行，则x自增1，y初始化为0，若此时x还是小于总行数，说明下一个值可以被取出来，那么在next函数就可以直接取出行为x，列为y的数字，并将y自增1
public class Vector2D implements Iterator<Integer> {
    private List<List<Integer>> v = null;
    private int x,y;
    public Vector2D(List<List<Integer>> vec2d) {
        v = vec2d;
        x = y = 0;
    }

    @Override
    public Integer next() {
        return v.get(x).get(y++);
    }

    @Override
    public boolean hasNext() {
        while (x < v.size() && y == v.get(x).size()) {
            x++; 
            y = 0;
        }
        return x < v.size();
    }
}

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i = new Vector2D(vec2d);
 * while (i.hasNext()) v[f()] = i.next();
 */
