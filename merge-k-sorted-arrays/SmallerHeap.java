//jz beats 98.40%, use smaller pq
//time: pq size is k, pq.offer poll time is O(lgk), so the total time is O(Nlogk), which overcome the challenge
//space O(N)
class Element {
    public int row, col, val;
    Element(int row, int col, int val) {
        this.row = row;
        this.col = col;
        this.val = val;
    }
}

public class Solution {
    private Comparator<Element> EC = new Comparator<Element>() {
        public int compare(Element left, Element right) {
            return left.val - right.val;
        }
    };
    
    /**
     * @param arrays k sorted integer arrays
     * @return a sorted array
     */
    public int[] mergekSortedArrays(int[][] arrays) {
        if (arrays == null) {
            return new int[0];
        }
        
        int total_size = 0;
        Queue<Element> Q = new PriorityQueue<Element>( //size of the queue = number of the arrays
            arrays.length, EC);
        
        //put each array's first element into heap  
        for (int i = 0; i < arrays.length; i++) {
            if (arrays[i].length > 0) {
                Element elem = new Element(i, 0, arrays[i][0]);
                Q.add(elem);
                total_size += arrays[i].length;
            }
        }
        
        int[] result = new int[total_size];
        int index = 0;
        while (!Q.isEmpty()) {
            //take one from Q and add one from Q
            Element elem = Q.poll();
            result[index++] = elem.val;
            // ir elem's array still have elements, 
            if (elem.col < arrays[elem.row].length-1) { //last elem is length-1
                elem.col += 1;
                elem.val = arrays[elem.row][elem.col];
                Q.add(elem);
            }
        }
        
        return result;
    }
}
