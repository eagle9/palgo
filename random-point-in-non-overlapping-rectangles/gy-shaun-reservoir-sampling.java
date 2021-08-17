//gy reservior sampling, shaun understood
class Solution {
    int [][] rects;
    int totalArea;
    TreeMap<Integer, Integer> areaToIdx = new TreeMap<>();
    public Solution(int[][] rects) {
        this.rects = rects;
        totalArea = 0;
        for (int [] rect : rects) {
            //deltaX * deltaY
            totalArea += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            //totalArea to rect idx
            areaToIdx.put(totalArea, areaToIdx.size());
        }
    }
    
    public int[] pick() {
        Random rand = new Random();
        int val = rand.nextInt(totalArea);
        //int idx = areaToIdx.upper_bound(val)->second;
        //least key that >= val
        int k = areaToIdx.higherKey(val);
        int idx = areaToIdx.get(k);
        int width = rects[idx][2] - rects[idx][0] + 1;
        int height = rects[idx][3] - rects[idx][1] + 1;
        
        return new int [] {rand.nextInt(width) + rects[idx][0], rand.nextInt(height) + rects[idx][1]};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * int[] param_1 = obj.pick();
 */

//gy reservior sampling 

