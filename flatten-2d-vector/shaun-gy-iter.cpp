//use vector's own iterator in c++, iterator for rows, int y for columns
//runtime 52ms, faster than 72%, mem less than 97%
//cutting: vector iterator for rows, int y for columns, how to reset y to 0?  when y == row.size()
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d): x(vec2d.begin()), end(vec2d.end()) {}
    
    int next() {
        //hasNext();
        while (x != end && y == (*x).size()) {
            ++x; //next row
            y = 0;
        }
        return (*x)[y++];
    }
    bool hasNext() {
        
        while (x != end && y == (*x).size()) {
            ++x; //next row
            y = 0;
        }
        return x != end;
    }
private:
    vector<vector<int>>::iterator x, end; //x is the cursor, end is the end row
    int y = 0;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
