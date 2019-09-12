//xss idea, close idea, wrong answer, use float as key directly won't work
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxPts = 0;
        for(int i=0; i<points.size(); i++) {
            int nMax = 0, nSame = 0, nInf = 0;
            unordered_map<float,int> comSlopes;
            
            for(int j=i+1; j<points.size(); j++) {
                if(points[j][0]==points[i][0]) {
                    if(points[j][1]==points[i][1])
                        nSame++;
                    else
                        nInf++;
                    continue;
                }
                float slope = (float)(points[j][1]-points[i][1])/(float)(points[j][0]-points[i][0]);
                comSlopes[slope]++;
                nMax = max(nMax, comSlopes[slope]);
            }
            
            nMax = max(nMax, nInf)+nSame+1;
            maxPts = max(maxPts,nMax);
        }
        return maxPts;
    }
};
