//use donglin's binary search template
//runtime 76ms, faster than 93%, memory less than 95%
class Solution1 {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int n = heaters.size();
        int r = INT_MIN;
        //for each house, find its left and right heaters
        //   or find first heater >= house
        for (const int house: houses) {
            int left = 0, right = n-1;
            while (left <= right) {
                int mid = left + (right - left)/2;
                //if == target, try go left, go get first n >= target
                if (heaters[mid] < house) left = mid+1; //squeeze to right
                else  { //target <= heaters[mid], squeeze to left
                    right = mid-1;
                }
            }
            //exit: right left
            //       -1    0      target < all
            
            if (right == -1)  { // target  ht0
                r = max(r,heaters[0] - house);
            }else if (left == n) { //   ht[n-1]  target
                r = max(r,house - heaters[n-1]);
            }else {
                //left is first heater >= house:  right house left
                //house can be covered by left or right, take min
                r = max(r, min(house-heaters[right], heaters[left] - house));
            }
        }
        return r;
    }
};
//use std lib lower_bound and review
//auto it = lower_bound(first, last, val)  val as lb, you >= val, val <=*it
//auto it = upper_bound(first,last, val)  val as ub, you > val,  val < *it
//runtime 80ms, faster than 80%, memory less than 98%
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int n = heaters.size();
        int r = INT_MIN;
        //for each house, find its left and right heaters
        //   or find first heater >= house
        for (const int house: houses) {
            //house as lower_bound of ...., first num >= house
            auto it = lower_bound(heaters.begin(), heaters.end(),house);
            
            if (it == heaters.begin()) { // target  ht0
                r = max(r,heaters[0] - house);
            }else if (it == heaters.end()) { //   ht[n-1]  target
                r = max(r,house - heaters[n-1]);
            }else {
                //left is first heater >= house:  right house left
                //house can be covered by left or right, take min
                r = max(r, min(house-*(it-1), *it - house));
            }
        }
        return r;
    }
};
