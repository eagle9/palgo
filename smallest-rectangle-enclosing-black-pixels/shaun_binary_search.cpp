//lt binary search, shaun came up with binary search rough idea after hint, tried to code with binary search template
//runtime 52ms, faster than 85%, mem less than 100%
typedef vector<vector<char>> vvc;
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        m = image.size(); 
        n = image[0].size();
        int left =  search2left(image, 0,  y, 0,m-1);
        int right = search2right(image,y, n-1, 0,m-1);
        int top =  search2top(image, 0,  x, left, right);
        int bottom=search2bottom(image, x,m-1, left, right);
        return (right - left+1) * (bottom - top+1);
    }
private:
    int m,n;
    bool col_has_black(vvc& image,int col, int top, int bottom) {
        for (int row = top; row <= bottom; ++row)
            if (image[row][col] == '1') return true;
        return false;
    }
    
    int search2left(vvc& image, int left, int right, int top, int bottom) {
        while (left+1 < right) {
            int mid = (left + right) / 2;
            //column mid has 1?
            bool hasb = col_has_black(image, mid, top, bottom);
            
            if (hasb) right = mid; //search the boundary in the smaller half, right reduced
            else left = mid + 1; //went left too much, go back right
        }
        //left right next to each other now,
        if (col_has_black(image,left,top,bottom)) return left;
        else return right;
       
    }
    
    int search2right(vvc& image, int left, int right, int top, int bottom) {
        while (left+1 < right) {
            int mid = (left + right) / 2;
            //column mid has 1?
            bool black = col_has_black(image, mid, top, bottom);
            if (black) left = mid;  // try to extend to right, left pushed to right
            else right = mid -1; //went right too much, go back left
        }
        //left right next to each other now,
        if (col_has_black(image,right,top,bottom)) return right;
        else return left;
    }
    
    bool row_has_black(vvc& image,int row, int left, int right) {
        for (int col = left; col <= right; ++col)
            if (image[row][col] == '1') return true;
        return false;
    }
    
    int search2top(vvc& image, int top, int bottom, int left, int right) {
        while (top + 1 < bottom) {
            int mid = (top + bottom) / 2;
            bool hasBlack = row_has_black(image,mid,left,right);
            if (hasBlack) bottom = mid;  //extend up
            else top = mid + 1; //went up too much, go back down
        }
        if (row_has_black(image,top,left,right)) return top;
        else return bottom;
    }
    
    int search2bottom(vvc& image, int top, int bottom, int left, int right) {
        while (top + 1 < bottom) {
            int mid = (top + bottom) / 2;
            bool hasBlack = row_has_black(image,mid,left,right);
            if (hasBlack) top = mid;  //extend down
            else bottom = mid -1; //went down too much, go back dup
        }
        if (row_has_black(image,bottom,left,right)) return bottom;
        else return top;
    }
};
