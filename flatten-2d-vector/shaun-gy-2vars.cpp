//grandyang use existing 2d vector for primary storage, and use only 2 variables 
//row and col
//runtime 52ms, faster than 72%, mem less than 100%
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d): data(vec2d), x(0), y(0) {}

    int next() {
        hasNext();
        return data[x][y++];
    }
    bool hasNext() {
        while (x < data.size() && y == data[x].size()) {
            ++x; 
            y = 0;
        }
        return x < data.size();
    }    
private:
    vector<vector<int>> data;
    int x, y;
};
/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
