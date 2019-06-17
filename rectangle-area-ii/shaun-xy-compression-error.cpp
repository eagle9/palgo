#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
//to debug , check with lt solution and http://hehejun.blogspot.com/2018/09/leetcoderectangle-area-ii.html
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        //if (rectangles.empty()) return 0;
        //int N = rectangles.size();
        
        //get unique x and y, sort them, find their sorted index
        unordered_set<int> xs, ys;
        for (auto rect: rectangles) {
            xs.insert(rect[0]); xs.insert(rect[2]);
            ys.insert(rect[1]); ys.insert(rect[3]);
        }
        //sorted index to x or y
        vector<int> imapx(xs.begin(), xs.end()), imapy(ys.begin(), ys.end());
        sort(imapx.begin(), imapx.end());
        sort(imapy.begin(), imapy.end());
        
        //reverse the mapping, x/y to its sorted index
        unordered_map<int,int> xmap, ymap;
        for (int i = 0; i < imapx.size(); ++i) xmap[imapx[i]] = i;
        for (int i = 0; i < imapy.size(); ++i) ymap[imapy[i]] = i;
        
        //fill the grid according to the rectangles
        int m = imapx.size(), n = imapy.size();
        vector<vector<bool>> grid(m, vector<bool>(n));
        for (auto rect: rectangles) {
            for (int i = xmap[rect[0]];i < xmap[rect[2]];++i) {
                for (int j = ymap[rect[1]]; j < ymap[rect[3]]; ++j) {
                    grid[i][j] = true;
                }
            }
        }
        cout <<"live here" << endl;
        
        //compute area according to grid, overlap considered
        long ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++i) {
                if (grid[i][j]) {
                    //    i  i+1
                    // j  []
                    //j+1
                    ans += (long)(imapx[i+1] - imapx[i]) * (long)(imapy[j+1] - imapy[j]);
                }
            }
        }
        ans %= 1000000007;
        return (int) ans;
         
    }
};
int main() {
	vector<vector<int>> rectangles = {{0,0,2,2},{1,0,2,3},{1,0,3,1}};
	int ans = Solution().rectangleArea(rectangles);
	cout << "ans = " << endl;
}
