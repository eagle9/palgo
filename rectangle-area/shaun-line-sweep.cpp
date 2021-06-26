//shaun use rectangle area ii approach -- line sweep
//accepted after fixing two bugs: 
//bug 1 --- cur starts with INT_MIN, not -1
//runtime 16ms, faster than 75.78%, mem less than 5%
//use vector.reverse(SIZE) and emplace_back
enum TYPE {OPEN,CLOSE};
class Solution {
private:
    struct Event {
        int y, x1, x2;
        TYPE type; 
        Event(int y, TYPE type, int x1, int x2): y(y), type(type), x1(x1), x2(x2) {}
        bool operator<(Event other) {
            return y < other.y;
        }
    };
    
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    
        vector<Event> events;
        events.reserve(4);
        vector<vector<int>> rectangles= {{A,B,C,D},{E,F,G,H}};
        for (vector<int> rec: rectangles) {
            events.emplace_back(rec[1], OPEN, rec[0], rec[2]);
            events.emplace_back(rec[3], CLOSE, rec[0], rec[2]);
        }
        sort(events.begin(), events.end());
        
        vector<pair<int,int>> active; //active intervals during line sweep
        int cur_y = events[0].y;
        int ans = 0;
        for (auto event: events) {
            int y = event.y, type = event.type, x1 = event.x1, x2 = event.x2;

            // Calculate query, merge intervals
            int query = 0;
            int cur = INT_MIN; //bug int cur = -1
            for (auto intv: active) {
                //intv.first intv.second contributes to the area???
                cur = max(cur, intv.first); //cur is prev interval's end, if its greater, take cur
                query += max(intv.second - cur, 0); //contribution to width, xs.second > cur to contribute, otherwise overlapping
                cur = max(cur, intv.second);
            }

            ans += query * (y - cur_y);

            if (type == OPEN) { //OPEN add interval to active
                active.emplace_back(x1, x2);
                sort(active.begin(), active.end());
            } else { //CLOSE erase interval from active
                for (int i = 0; i < active.size(); ++i) {
                    if (active[i].first == x1 && active[i].second == x2) {
                        active.erase(active.begin()+i);
                        break;
                    }
                }
            }

            cur_y = y;
        }
         return ans;
    }
};
