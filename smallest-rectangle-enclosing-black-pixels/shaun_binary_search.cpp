//lt binary search, shaun came up with binary search rough idea, deep read the code and modified to my own idea 
//runtime 52ms, faster than 83%, mem less than 100%
typedef vector<vector<char>> vvc;
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        int left =  searchColumns(image, 0,  y, 0,m,true);
        int right = searchColumns(image,y+1, n, 0,m,false);
        int top =  searchRows(image, 0,  x, left, right, true);
        int bottom=searchRows(image, x+1,m, left, right, false);
        return (right - left) * (bottom - top);
    }
private:
    int searchColumns(vvc& image, int i, int j, int top, int bottom, bool goSmall) {
        
        while (i != j) {
            int mid = (i + j) / 2;
            //column mid has 1?
            bool hasBlack = false;
            for (int k = top; k < bottom; ++k) {
                if (image[k][mid] == '1') {
                    hasBlack = true; break;
                }
            }
            
            //draw a picture,   goSmall && black, go small; white && goSmall, go up 
            if (goSmall) { //i == j exit, i == black
                if (hasBlack) j = mid; //search the boundary in the smaller half, j reduced
                else i = mid + 1;//search the boundary in the greater half, i incrased
            }else {   // i==j 1 after black
                if (hasBlack) i = mid + 1;
                else j = mid;
            }
            
        }
        //i == j now
        return i;
    }
    int searchRows(vvc& image, int i, int j, int left, int right, bool goSmall) {
        while (i != j) {
            int mid = (i + j) / 2;
            //mid row has 1 pixel???
            bool hasBlack = false;
            for (int k = left; k< right; ++k) {
                if (image[mid][k] == '1') {
                    hasBlack = true;
                    break;
                }
            }
            //draw a picture,   goSmall && black, go small; white && goSmall, go up 
            if (goSmall) { //i == j exit, i == black
                if (hasBlack) j = mid; //search the boundary in the smaller half, j reduced
                else i = mid + 1;//search the boundary in the greater half, i incrased
            }else {   // i==j 1 after black
                if (hasBlack) i = mid + 1;
                else j = mid;
            }
        }
        return i;
    }
};
