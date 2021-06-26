/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
/*
You need to implement hashCode() and equals(). compareTo() is additionally required for sorted map/set.
*/
/*
grandyang idea, shaun comes up with similar idea, but missed two points: 
1) dealing with duplicates
2) use gcd to get key, avoid floating in slope representation
Runtime: 15 ms, faster than 66.09% of Java online submissions for Max Points on a Line.
Memory Usage: 36.9 MB, less than 100.00% of Java online submissions for Max Points on a Line.
above speed is achieved using Pair class, string as key a little slower, int[] as pair key does not work
*/
/*
public class Pair {

    private final int x;
    private final int y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Pair)) return false;
        Pair key = (Pair) o;
        return x == key.x && y == key.y;
    }

    @Override
    public int hashCode() {
        int result = x;
        result = 31 * result + y; //31 here, any multiplier is okay
        return result;
    }

}
or you can just use javafx.util.Pair class
to be comparable, you use a comparator, for example
private Comparator<Pair> pairComparator = new Comparator<Pair>() {
    public int compare(Pair left, Pair right) {
        if (left.value != right.value) {
            return left.value - right.value;
        }
        return right.key.compareTo(left.key);
    }
};
         
Q = new PriorityQueue<Pair>(k, pairComparator);
*/
import javafx.util.Pair;
class Solution {
    public int maxPoints(Point[] points) {
        int res = 0;
       
        for (int i = 0; i < points.length; i++) {
            //Map<int[],Integer> map = new HashMap<>(); using int [] for pair not work
            Map<Pair,Integer> map = new HashMap<>(); //works, how about move this to outside of loop, if you do so, wrong answer, why???
            //Map<String,Integer> map = new HashMap<>(); //works
            int duplicate = 1;
            for (int j = i+1; j < points.length; j++) {
                //deal with duplicate points, shaun missed this one
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate++;
                    continue;
                }
                //dx and dy won't be 0
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int div = gcd(dx,dy);
                //int [] pair = new int [] {dx/div, dy/div};
                Pair pair = new Pair(dx/div, dy/div);
                //String pair = dx/div + "," + dy/div;
                map.putIfAbsent(pair,0);
                map.put(pair,map.get(pair)+1);
            }
            //update res with duplicates and point count
            res = Math.max(res,duplicate);
            //for (int [] pair: map.keySet()) {
            for (Pair pair: map.keySet()) {
            //for (String pair: map.keySet()) {
                res = Math.max(res, map.get(pair) + duplicate);
            }
        }
        return res;
    }
    
    public int gcd1(int a, int b) { //works, but why not a==0 check
        return (b==0)? a : gcd(b, a%b);
    }
    public int gcd2(int a, int b) { //stack overflow if you don't put smaller number as the first parameter
        return (a==0)? b : gcd(b%a,a);
    }

}

