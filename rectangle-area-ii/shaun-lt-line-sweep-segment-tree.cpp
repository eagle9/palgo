//shaun lt line sweep with segment tree
//to read and understand more
//runtime 8ms, faster than 97.89%, mem less than 14%
//lt official in c++, http://hehejun.blogspot.com/2018/09/leetcoderectangle-area-ii.html
//i only ask myself to read and understand, learn the idea and coding
// nullptr ----> NULL
// user vector<int> rather than event with 4 fields, still in order
class Node {
public:
   int cnt;//The total # of times that existing ranges can be splitted into this piece
   int coveredRange;
   int start, end;
   Node* left, *right;

   Node(int s, int e): start(s), end(e){
      cnt = 0;
      coveredRange = 0;
      left = nullptr;
      right = nullptr;
   }

   Node* getLeft() {
      if (start > end) return nullptr;
      if (left) return left;
      int mid = start + (end - start) / 2;
      left = new Node(start, mid);
      return left;
   }

   Node* getRight() {
      if (start > end) return nullptr;
      if (right) return right;
      int mid = start + (end - start) / 2;
      right = new Node(mid, end);
      return right;
   }

   void update(int s, int e, int val, vector<int>& map){
      if (s <= start && e >= end) cnt += val;
      else if (s >= end || e <= start)
         return;
      else {
         getLeft()->update(s, e, val, map);
         getRight()->update(s, e, val, map);
      }
      coveredRange = cnt ? map[end] - map[start] : (start + 1 >= end? 0 : getLeft()->coveredRange + getRight()->coveredRange);
   }
};

class Solution {
public:
   int rectangleArea(vector<vector<int>>& rectangles) {
      if (rectangles.empty())return 0;
      const int MOD = 1000000007;
      vector<vector<int>> events;
      vector<int> xs;
      for (const auto& rectangle : rectangles) {
         int x1 = rectangle[0], x2 = rectangle[2], y1 = rectangle[1], y2 = rectangle[3];
         events.push_back({y1, 1, x1, x2});
         events.push_back({ y2, -1, x1, x2 });
         xs.push_back(x1);
         xs.push_back(x2);
      }
      /*
      auto comp = [](const vector<int>& lhs, const vector<int>& rhs) {
         return lhs[0] == rhs[0] ? lhs[1] > rhs[1]: lhs[0] < rhs[0];
      };*/
      struct {
        bool operator()(const vector<int>& lhs, const vector<int>& rhs) const {
            return lhs[0] == rhs[0] ? lhs[1] > rhs[1]: lhs[0] < rhs[0];
        };
      } comp;
      sort(events.begin(), events.end(), comp);
      sort(xs.begin(), xs.end());
      int len = events.size();
      //compress input size by mapping it to [0, len - 1]
      unordered_map<int, int> xMap;
      for (int i = 0; i < len; ++i)xMap[xs[i]] = i;
      long area = 0;
      int last_y = events[0][0];
      Node* root = new Node(0, len - 1);
      root->update(xMap[events[0][2]], xMap[events[0][3]], events[0][1], xs);
      for (int i = 1; i < len; ++i){
         auto event = events[i];
         int y = event[0];
         area += static_cast<long>(y - last_y) * root->coveredRange;
         area %= MOD;
         root->update(xMap[event[2]], xMap[event[3]], event[1], xs);
         last_y = y;
      }
      return area;
   }
};
