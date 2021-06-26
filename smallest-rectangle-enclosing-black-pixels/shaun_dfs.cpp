//shaun dfs idea, runtime 56ms, faster than 61%, mem less than 62%
//time complexity : O(E) = O(B) = O(mn)O(E)=O(B)=O(mn).
//Space complexity : O(V) = O(B) = O(mn)O(V)=O(B)=O(mn).
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty()) return 0;
        m = image.size();
        n = image[0].size();
        //rectangle parameters
        top = bottom = x;
        left =right = y;
        dfs(image, x, y);
        return (bottom +1 - top) * (right+1 - left);
    }
private:
    int m, n;
    int top, bottom, left, right;
    void dfs(vector<vector<char>>& image, int x, int y) {
        //recur exit
        if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] == '0') return;
        //update top,bottom, left, right during dfs
        image[x][y] = '0'; //mark xy as visisted
        top = min(top,x);
        bottom = max(bottom,x);
        left = min(left, y);
        right= max(right, y);
        dfs(image, x, y+1);
        dfs(image,x, y-1);
        dfs(image, x+1, y);
        dfs(image, x-1, y);
    }
    
};
