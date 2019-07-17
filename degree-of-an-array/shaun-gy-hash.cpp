/*
runtime 40ms, faster than 83%, mem less than 59%
shaun idea: loop the numbers, keep update degree for each number, also the number's start and end index,  track the max degree

then for all number with the max degree, choose the minimum end-start+1 

shaun and gy have the same idea,  gy's use int -> pair<int,int> to store each number's start and end, start update when ++count == 1

*/
class Solution1 {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int degree = 0; //max rep count of all numbers
        unordered_map<int, int> m; //number to its count
        unordered_map<int, pair<int, int>> pos; //number to its start and end index
        for (int i = 0; i < nums.size(); ++i) {
            if (++m[nums[i]] == 1) {
                pos[nums[i]] = {i, i};
            } else {
                //nums[i] count > 1, only update end index
                pos[nums[i]].second = i;
            }
            //keep track of the max count
            degree = max(degree, m[nums[i]]);
        };
        int res = INT_MAX; // res is the minimum subarray length
        for (auto a : m) {
            //a.first(number), a.second(count)
            //p[number].first = start, p[].second= end
            if (a.second == degree) {
                res = min(res, pos[a.first].second - pos[a.first].first + 1);
            }
        }
        return res;
    }
};


//one pass, harder to write, not easy to read
//just for reference
//runtime 44ms, faster than 68%, mem less than 58%
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MAX; //minimum length of subarray with max degree
        int degree = 0; //max count of elements
        unordered_map<int, int> m, startIdx; //m: number to its count, startIdx: number to its start index
    
        for (int i = 0; i < n; ++i) {
            ++m[nums[i]];
            
            if (!startIdx.count(nums[i])) startIdx[nums[i]] = i;
            
            if (m[nums[i]] == degree) {
                res = min(res, i - startIdx[nums[i]] + 1);
            } 
            //update degree
            else if (m[nums[i]] > degree) {
                res = i - startIdx[nums[i]] + 1;
                degree = m[nums[i]];
            }
        }
        return res;
    }
};
