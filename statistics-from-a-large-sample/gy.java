class Solution {
    public double[] sampleStats(int[] count) {
        
        double mn = 256, mx = 0, mean = 0, median = 0, sum = 0;
        int cnt = 0, mode = 0;
        for (int i = 0; i < count.length; ++i) {
            if (count[i] == 0) continue;
            //count[i] != 0, update min
            if (mn == 256) mn = i; //update once
            mx = i; //max, keep updating
            sum += (double)i * count[i];
            cnt += count[i];
            if (count[i] > count[mode]) mode = i; //update mode
        }
        mean = sum / cnt;
        // 1 2 3 4 5
        //  
        int first = (cnt + 1) / 2, second = (cnt + 2) / 2, cur = 0;
        for (int i = 0; i < count.length; ++i) {
            if (cur < first && cur + count[i] >= first) median += i / 2.0;
            if (cur < second && cur + count[i] >= second) median += i / 2.0;
            cur += count[i];
        }
        return new double [] {mn, mx, sum / cnt, median, (double)mode};
    }
}
