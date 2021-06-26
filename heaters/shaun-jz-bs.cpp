//start with a large radiuis, [0=left, large=right], if all houses can be warmed, (left, mid), some houses not warmed, [mid, right] 
//how to check all houses can be warmed, given a radius and heater positions? 
//for each house pos, can we find h, such that   h-r <=pos <= h+r, this going to be O(mn)

//shaun jz template, runtime 76ms, faster than 93%
//jz idea --- cutting: sort header, for each house, find first heater index >= house, then the radius to cover this house is     heater[index-1] house heater[index], take the min from these two heaters
// then take the max of such a radius
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int n = heaters.size();
        
        int r = INT_MIN;
        //for each house, find its left and right heaters
        //   or find first heater >= house
        for (const int house: houses) {
            int left = 0, right = n-1;
			//find first header >= house
            while (left+1< right) {
                int mid = left + (right - left)/2;
                //if == target, try go left, go get first n >= target
                if (heaters[mid] < house) left = mid+1; //squeeze to right
                else  { //target <= heaters[mid], squeeze to left
                    right = mid;
                }
            }
            //exit: left right next to each other and in bound
            
            if (house < heaters[0])  { // target(house)  < all
                r = max(r,heaters[0] - house);
            }else if (heaters[n-1] < house) { //   all <  target
                r = max(r,house - heaters[n-1]);
            }else {
                //now  ht[0] <= house target <= ht[n-1], look for first heater >= house
                int pos = (heaters[left] >= house)? left: right;
                //  pos-1  house  pos
                //house can be covered by left or right, take min
                //int r_right = heaters[pos] - house;
                //int r_left = pos - 1 >=0? house - heaters[pos-1]: INT_MAX;
                //r = max(r, min(r_left, r_right));
                r = max(r, min(pos-1>=0? house-heaters[pos-1]:INT_MAX, heaters[pos] - house));
            }
        }
        return r;
    }
};
class Solution2 {
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


//use donglin's binary search template
//runtime 76ms, faster than 93%, memory less than 95%
class Solution3 {
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

