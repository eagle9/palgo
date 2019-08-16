//lt greedy and sorting idea, shaun read and understand
//cutting: sort people by height(descending) and k infront (ascending), use the example to figure out, insert at index
//runtime 76ms, faster than 76%, mem less than 29%
struct pCompare {
            bool operator()(vector<int>& a, vector<int>& b) const {
                return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
            }
        };
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);});
        /*sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });*/
        //sort(people.begin(), people.end(), pCompare());
        vector<vector<int>> res;
        
        for (int i = 0; i < people.size(); i++) {
            auto p = people[i];
            //p0 height, p1 k people in front
            
            res.insert(res.begin() + p[1],p);
           
        }
        return res;
    }
};

