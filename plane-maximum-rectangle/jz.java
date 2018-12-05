//jz h student, beats 17%, use string hash
/*
idea 
h同学
更新于 11/4/2018, 7:59:51 AM
for each point, hash them (string concat) and put them into set for easy lookup.

then for each point, find all of its top-right diagonal points if they exist

as long as the coordinate x and y are both larger than current point's coordinate - it'll be a valid top-right diagonal
With the point and the list of diagonal - we have a rectangle - see if the other two points exist or not in the plane

If the other two points both exist - calculate area and 打擂台

*/
public class Solution {
    /**
     * @param a: the points
     * @return: return the maximum rectangle area
     */
    public int getMaximum(int[][] a) {
        Set<String> s = new HashSet<String>();
        
        for (int i = 0; i < a.length; i++) {
            s.add(""+a[i][0]+" "+a[i][1]);
        }
        
        int maxArea = 0;
        for (int i = 0; i < a.length; i++) {
            int [] current = a[i];
            
            // find all diagnals on top and right
            List<String> diagnals=findDiagnals(current, s);
            
            int area = calcAreaIfValid(diagnals, current, s);
            maxArea = Math.max(maxArea, area);
        }
        return maxArea;
    }
    
    // only find diagnal on top right
    private List<String> findDiagnals(int [] current, Set<String> s) {
        List<String> result = new ArrayList<String>();
        for (String c : s) {
            int [] coord = convertCoord(c);
            if (coord[0] > current[0] && coord[1] > current[1]) {
                result.add(c);
            }
        }
        return result;
    }
    
    private int [] convertCoord(String c) {
        int [] coord = new int [2];
        String [] ca = c.split(" ");
        
        for (int i = 0; i < ca.length; i++) {
            coord[i] = Integer.valueOf(ca[i]);
        }
        return coord;
    }
    
    private int calcAreaIfValid(List<String> diagnals, int [] current, Set<String> s) {
        if (diagnals.size() == 0) {
            return -1;
        }
        
        int maxArea = -1;
        
        for (String d : diagnals) {
            // top right - current is bot left
            int [] diag = convertCoord(d); 
            String topLeft = current[0]+" "+diag[1];
            String botRight = diag[0]+" "+current[1];
            
            if (s.contains(topLeft) && s.contains(botRight)) {
                maxArea = Math.max(maxArea, (diag[0]-current[0])*(diag[1]-current[1]));
            }
        }
        return maxArea;
    }
}
