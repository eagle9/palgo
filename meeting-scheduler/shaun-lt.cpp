/*
Runtime: 256 ms, faster than 64.43% of C++ online submissions for Meeting Scheduler.
Memory Usage: 28.2 MB, less than 100.00% of C++ online submissions for Meeting Scheduler.

*/
class Solution {
public:
    typedef pair<int, bool> slot;
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
      vector<slot> slots;
      for (const auto& s: slots1) {
        if ( (s[1] - s[0]) >= duration ) {
		 //Duration requirement is met, add the edges
          slots.emplace_back(s[0], true);
          slots.emplace_back(s[1], false);
        }
      }
      for (const auto& s: slots2) {
        if ( (s[1] - s[0]) >= duration ) {
          slots.emplace_back(s[0], true);
          slots.emplace_back(s[1], false);
        }
      }
      
      sort(slots.begin(), slots.end());
      int open = 0; //Track number of open intervals
      int start = 0; //Track the start time of second open interval
      for (const auto& s: slots) {
        if (s.second) {
          open++;
        } else {
          if (open == 2) {
		   // Close edge when both parties have an open interval
		   // check if the interval satisfies the duration requirement
            int d = s.first - start;
            if (d >= duration) return { start, start+duration};
          }
          open--; //Close edge, decrement the count
        }
        if (open == 2) start = s.first; // Both parties now have an open interval, start time is the max of the two, which is current value
      }
      return {};
    }
	
};
