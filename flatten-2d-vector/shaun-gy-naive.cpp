/*
grandyang naive design, cutting: 2d to 1 d vector, use i to track current element index
runtime 52ms, faster than 72%, mem less than 97%
*/
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for (auto& a : vec2d) {
            v.insert(v.end(), a.begin(), a.end());
        }    
    }
    int next() {
        return v[i++];
    }
    bool hasNext() {
        return i < v.size();
    }
private:
    vector<int> v;
    int i = 0;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
