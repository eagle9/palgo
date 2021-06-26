//lt discuss idea, sort all work - bike distance, then consider each distance in order, track if a worker/bike is assigned or not

//runtime 216ms, faster than 70%, mem less than 100%

class Solution {
    class DComp implements Comparator<Distance> {
        //public int compareTo(Distance a, Distance b) { //bug should be compare
        public int compare(Distance a, Distance b) { 
            int res = Integer.compare(a.mDist, b.mDist);
            if (res == 0) {
                res = Integer.compare(a.mWorker, b.mWorker); //smaller work index
                if (res == 0)
                    res = Integer.compare(a.mBike, b.mBike);
            }
            return res;
            
        }
    }
    public int[] assignBikes(int[][] workers, int[][] bikes) {
        int nWorkers = workers.length;
        int nBikes = bikes.length;
        
        int[] result = new int[nWorkers];
        Arrays.fill(result, -1);
        
        ArrayList<Distance> dist = new ArrayList(nWorkers * nBikes);
        
        for(int i =0; i < workers.length; i++){
            int[] worker = workers[i];
            for(int j =0; j< bikes.length; j++){
                int[] bike = bikes[j];
                int distance = Math.abs(worker[0] - bike[0]) + Math.abs(worker[1] - bike[1]);
                dist.add(new Distance(distance, i, j));
            }
            
        }
        
        // the latest java 
        /*
        Collections.sort(dist, (a, b) -> {
            int comp = Integer.compare(a.mDist, b.mDist);
            if(comp ==0){
                comp = Integer.compare(a.mWorker, b.mWorker);
                if(comp == 0){
                    comp = Integer.compare(a.mBike, b.mBike);
                }
            }
            return comp;
        });
        */
        Collections.sort(dist,new DComp());
        
        boolean[] assWorkers = new boolean[nWorkers];
        boolean[] assBikes = new boolean[nBikes];
        
        int count = 0;
        
        for(int i =0; i< dist.size(); i++){
            if(count == nWorkers){
                break;
            }
            Distance d = dist.get(i);
            //worker bike not yet assigned
            if(!assWorkers[d.mWorker] && !assBikes[d.mBike]){
                count++;
                assWorkers[d.mWorker] = true;
                assBikes[d.mBike] = true;
                result[d.mWorker] = d.mBike;
            }
        }
        
        return result;
    }
    
    class Distance  {
        int mDist = -1;
        int mWorker; //worker index
        int mBike; //bike index
        
        public Distance(int dist, int worker, int bike){
            mDist = dist;
            mWorker = worker;
            mBike = bike;
        }
    }
}
